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

//�Ľ���ð������
void BubbleSort(SqList& L) {
	int flag = 1; //flag��Ϊ�Ƿ񽻻��ı��
	RedType temp; //����ʱ��ʱ�洢
	for (int i = 1; i <= L.length - 1 && flag==1; i++) { //�ܹ���Ҫ��L.length-1����
		flag = 0;
		for (int j = 1; j <= L.length - i; j++){ //��i����Ҫ�Ƚϣ�L.length-1-i����
			if (L.elem[j].key > L.elem[j + 1].key) { //��������
				flag = 1; //����������flag��Ϊ1��������û����������flag����Ϊ0
				temp = L.elem[j]; 
				L.elem[j] = L.elem[j + 1]; 
				L.elem[j + 1] = temp; //����
			}
		}
	}
}

//���������Partition����
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
//��������
void QSort(SqList& L, int low, int high) //��˳���L��������
{
	//��������������������
	if (low < high) //���ȴ���1
	{
		//��L.elem[low...high]һ��Ϊ����privotlocΪ����Ԫ���ź����λ��
		int pivotloc = Partition(L, low, high); 
		//�ٶ����е���벿�ֽ�������������λ��
		QSort(L, low, pivotloc - 1);
		//�ٶ����е��Ұ벿�ֽ�������������λ��
		QSort(L, pivotloc + 1, high);
	}
}

int main()
{


	system("pause");
	return 0;
}