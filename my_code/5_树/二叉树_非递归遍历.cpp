#include <iostream>
using namespace std;

//�ǵݹ��㷨

struct SqStack {
	int* base;
	int* top;
	int stacksize;
};

typedef struct BiNode {
	int data;
	BiNode* lchild, * rchild;
}*BiTree;

//���������������--�ǵݹ��㷨
void ldr(BiTree& T)
{
    //��һ��������һ��ջ�����ڱ���������Ľ��
    SqStack S;
    InitSqStack(S);
    BiTree p = T;
    while (p || !IsEmpty(S))
    {
        if (p)
        {   //������ջ������������
            Push(S, p);
            p = p->lchild;
        }
        else
        {   //������ջ���������㣬����������
            Pop(S, p);
            visit(p);
            p = p->rchild;
        }
    }
}



int main()
{


	system("pause");
	return 0;
}