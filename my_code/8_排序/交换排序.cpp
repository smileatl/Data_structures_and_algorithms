#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef int KeyType; //设关键字为整型量(int型)
typedef int InfoType;

typedef struct { //定义每个记录（数据元素）的结构
	KeyType key; //关键字
	InfoType otherinfo; //其他数据项
}RedType; //Record Type

typedef struct { //定义顺序表的结构
	RedType elem[MAXSIZE + 1]; //存储顺序表的向量						
							//r[0]一般作哨兵或缓冲区
	int length; //顺序表的长度
}SqList;

//改进的冒泡排序
void BubbleSort(SqList& L) {
	int flag = 1; //flag作为是否交换的标记
	RedType temp; //交换时临时存储
	for (int i = 1; i <= L.length - 1 && flag==1; i++) { //总共需要（L.length-1）趟
		flag = 0;
		for (int j = 1; j <= L.length - i; j++){ //第i趟需要比较（L.length-1-i）次
			if (L.elem[j].key > L.elem[j + 1].key) { //发生逆序
				flag = 1; //发生交换，flag置为1，若本趟没发生交换，flag保持为0
				temp = L.elem[j]; 
				L.elem[j] = L.elem[j + 1]; 
				L.elem[j + 1] = temp; //交换
			}
		}
	}
}

//快速排序的Partition函数
int Partition(SqList& L, int low, int high) {
	L.elem[0] = L.elem[low];
	int privotkey = L.elem[0].key;
	while (low < high) {
		while (low < high && L.elem[high].key >= privotkey) {
			--high;
		}
		L.elem[low] = L.elem[high];
		while (low < high && L.elem[low].key < privotkey) {
			++low;
		}
		L.elem[low] = L.elem[0];
	}
	L.elem[low] = L.elem[0];
	return 0;
}
//快速排序
void QSort(SqList& L, int low, int high) //对顺序表L快速排序
{
	//好像二叉树的先序遍历啊
	if (low < high) //长度大于1
	{
		//将L.elem[low...high]一分为二，privotloc为数轴元素排好序的位置
		int pivotloc = Partition(L, low, high); 
		//再对序列的左半部分进行排序找中心位置
		QSort(L, low, pivotloc - 1);
		//再对序列的右半部分进行排序找中心位置
		QSort(L, pivotloc + 1, high);
	}
}

int main()
{


	system("pause");
	return 0;
}