#include <iostream>
using namespace std;

//顺序查找表的定义
#define MAXSIZE 100
typedef int KeyType;
typedef int InfoType;

//数据元素类型定义
struct ElemType {
	KeyType key; //关键字域
	InfoType otherinfo; //其他域
};
//顺序表结构类型定义，Sequential Search Table
struct SSTable { 
	ElemType* R; //顺序表地址指针
	int length; //顺序表的长度
};

//顺序查找算法
int SqSearch(SSTable& S, const KeyType e) {
	S.R[0].key = e;
	int i;
	for (i = S.length; S.R[i].key != e; i--) {
		; 
	}
	return i;
}

//二分查找法
int Search_bin(SSTable& S, const KeyType e) {
	int low = 1, high = S.length;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (e == S.R[mid].key) {
			return mid;
		}
		if (e < S.R[mid].key) {
			high = mid - 1;
		}
		if (e > S.R[mid].key) {
			low = mid = 1;
		}
	}
	return -1;
}

//二分查找算法递归版
int Search_bin_2(SSTable& S, const KeyType e, int low, int high) {
	if (low > high) {
		return -1;
	}
	int mid = (low + high) / 2;
	if (e == S.R[mid].key) {
		return mid;
	}
	if (e < S.R[mid].key) {
		return Search_bin_2(S, e, low, mid - 1);
	}
	else {
		return Search_bin_2(S, e, mid + 1, high);
	}
}

int main()
{


	system("pause");
	return 0;
}