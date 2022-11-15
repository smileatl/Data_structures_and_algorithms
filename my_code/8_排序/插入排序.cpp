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


//直接插入排序
void InsertSort(SqList& L) {
	for (int i = 2; i <= L.length; i++) { 
		L.elem[0] = L.elem[i]; //复制为哨兵
		int j = i - 1;
		for (; L.elem[0].key < L.elem[j].key; j--) { //若"<""，需将L.elem[i]插入有序字表
			L.elem[j + 1] = L.elem[j]; //记录后移
		}
		L.elem[j + 1] = L.elem[0]; //插入到正确位置
	}
}

//折半插入排序
void BInsertSort(SqList& L)
{
    for (int i = 2; i < L.length; ++i) //依次插入第2~第n个元素
    {
        L.elem[0] = L.elem[i]; //哨兵位
        int low = 1, high = i - 1; //采用二分查找法查找插入位置
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (L.elem[0].key < L.elem[mid].key)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            } //循环结束，high+1则为插入位置
        //这个排序的根本思想，是将折半排序的比较区间，逐渐缩小到最大的小于等于哨兵元素的那个元素的位置
        //然后这个位置再加1，就是此元素应该插入的位置
        for (int j = i; j >= high + 1; --j)
        {
            L.elem[j + 1] = L.elem[j]; //移动元素
        }
        L.elem[high + 1] = L.elem[0]; //插入到正确位置
    }
}

int main()
{


	system("pause");
	return 0;
}