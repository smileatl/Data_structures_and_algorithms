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

//选择排序
void SelectSort(SqList& L) {
	RedType temp; //交换时临时存储
	for (int i = 1; i < L.length; i++) {
		int k = i;
		for (int j = i + 1; j <= L.length; j++) {
			if (L.elem[j].key < L.elem[k].key) {
				k = j; //记录最小值位置
			}
		}
		if (k != i) {
			temp = L.elem[k];
			L.elem[k] = L.elem[i];
			L.elem[k] = temp; //交换
		}
	}
}

int main()
{


	system("pause");
	return 0;
}