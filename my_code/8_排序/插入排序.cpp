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


//ֱ�Ӳ�������
void InsertSort(SqList& L) {
	for (int i = 2; i <= L.length; i++) { 
		L.elem[0] = L.elem[i]; //����Ϊ�ڱ�
		int j = i - 1;
		for (; L.elem[0].key < L.elem[j].key; j--) { //��"<""���轫L.elem[i]���������ֱ�
			L.elem[j + 1] = L.elem[j]; //��¼����
		}
		L.elem[j + 1] = L.elem[0]; //���뵽��ȷλ��
	}
}

//�۰��������
void BInsertSort(SqList& L)
{
    for (int i = 2; i < L.length; ++i) //���β����2~��n��Ԫ��
    {
        L.elem[0] = L.elem[i]; //�ڱ�λ
        int low = 1, high = i - 1; //���ö��ֲ��ҷ����Ҳ���λ��
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
            } //ѭ��������high+1��Ϊ����λ��
        //�������ĸ���˼�룬�ǽ��۰�����ıȽ����䣬����С������С�ڵ����ڱ�Ԫ�ص��Ǹ�Ԫ�ص�λ��
        //Ȼ�����λ���ټ�1�����Ǵ�Ԫ��Ӧ�ò����λ��
        for (int j = i; j >= high + 1; --j)
        {
            L.elem[j + 1] = L.elem[j]; //�ƶ�Ԫ��
        }
        L.elem[high + 1] = L.elem[0]; //���뵽��ȷλ��
    }
}

int main()
{


	system("pause");
	return 0;
}