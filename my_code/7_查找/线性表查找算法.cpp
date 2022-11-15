#include <iostream>
using namespace std;

//˳����ұ�Ķ���
#define MAXSIZE 100
typedef int KeyType;
typedef int InfoType;

//����Ԫ�����Ͷ���
struct ElemType {
	KeyType key; //�ؼ�����
	InfoType otherinfo; //������
};
//˳���ṹ���Ͷ��壬Sequential Search Table
struct SSTable { 
	ElemType* R; //˳����ַָ��
	int length; //˳���ĳ���
};

//˳������㷨
int SqSearch(SSTable& S, const KeyType e) {
	S.R[0].key = e;
	int i;
	for (i = S.length; S.R[i].key != e; i--) {
		; 
	}
	return i;
}

//���ֲ��ҷ�
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

//���ֲ����㷨�ݹ��
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