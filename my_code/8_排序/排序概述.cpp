#include <iostream>
using namespace std;

//�洢�ṹ-��¼������˳���洢
#define MAXSIZE 20 //���¼������20��

typedef int KeyType; //��ؼ���Ϊ������(int��)
typedef int InfoType;

typedef struct { //����ÿ����¼������Ԫ�أ��Ľṹ
	KeyType key; //�ؼ���
	InfoType otherinfo; //����������
}RedType; //Record Type
 
typedef struct { //����˳���Ľṹ
	RedType r[MAXSIZE + 1]; //�洢˳��������
							//r[0]һ�����ڱ��򻺳���
	int length; //˳���ĳ���
}SqList;



int main()
{


	system("pause");
	return 0;
}