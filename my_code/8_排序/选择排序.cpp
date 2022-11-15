#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef int KeyType; //��ؼ���Ϊ������(int��)
typedef int InfoType;

typedef struct { //����ÿ����¼������Ԫ�أ��Ľṹ
	KeyType key; //�ؼ���
	InfoType otherinfo; //����������
}RedType; //Record Type

typedef struct { //����˳���Ľṹ
	RedType elem[MAXSIZE + 1]; //�洢˳��������						
							//r[0]һ�����ڱ��򻺳���
	int length; //˳���ĳ���
}SqList;

//ѡ������
void SelectSort(SqList& L) {
	RedType temp; //����ʱ��ʱ�洢
	for (int i = 1; i < L.length; i++) {
		int k = i;
		for (int j = i + 1; j <= L.length; j++) {
			if (L.elem[j].key < L.elem[k].key) {
				k = j; //��¼��Сֵλ��
			}
		}
		if (k != i) {
			temp = L.elem[k];
			L.elem[k] = L.elem[i];
			L.elem[k] = temp; //����
		}
	}
}

int main()
{


	system("pause");
	return 0;
}