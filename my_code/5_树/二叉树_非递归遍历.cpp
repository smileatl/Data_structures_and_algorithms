#include <iostream>
using namespace std;

//非递归算法

struct SqStack {
	int* base;
	int* top;
	int stacksize;
};

typedef struct BiNode {
	int data;
	BiNode* lchild, * rchild;
}*BiTree;

//二叉树的中序遍历--非递归算法
void ldr(BiTree& T)
{
    //第一步：创建一个栈，用于保存二叉树的结点
    SqStack S;
    InitSqStack(S);
    BiTree p = T;
    while (p || !IsEmpty(S))
    {
        if (p)
        {   //根结点进栈，遍历左子树
            Push(S, p);
            p = p->lchild;
        }
        else
        {   //根结点出栈，输出根结点，遍历右子树
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