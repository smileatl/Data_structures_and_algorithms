#include <iostream>
using namespace std;

//�ݹ��㷨

//�������Ķ���
typedef struct BiNode {
	int data;
	BiNode* lchild, * rchild;
}*BiTree;


//���������������DLR
bool PreOrderTraverse(BiTree& T){
    if (T == nullptr)
    {
        return true;
    }
    //���ʸ����
    visit(T);
    //�ݹ��������
    PreOrderTraverse(T->lchild);
    //�ݹ�����Һ���
    PreOrderTraverse(T->rchild);
    return true;
}

//���������������LDR
bool InOrderTraverse(BiTree& T)
{
    if (T == nullptr)
    {
        return true;
    }
    //��һ������������
    InOrderTraverse(T->lchild);
    //�ڶ��������ʸ����
    visit(T);
    //�������������Һ���
    InOrderTraverse(T->rchild);
    return true;
}

//�������ĺ������
bool PostOrderTraverse(BiTree& T)
{
    if (T == nullptr)
    {
        return true;
    }
    //��һ������������
    PostOrderTraverse(T->lchild);
    //�ڶ����������Һ���
    PostOrderTraverse(T->rchild);
    //�����������ʸ����
    visit(T);
    return true;
}

//�������Ľ�����DLR����������ݹ��㷨��
bool CreateBiTree(BiTree& T) {
    int input;
    cin >> input;
    if (input = -1) {
        return false;
    }
    T = new BiNode;
    T->data = input;
    CreateBiTree(T->lchild);
    CreateBiTree(T->rchild);
    return true;
}

//�������ĸ���
bool CopyBiTree(const BiTree& T, BiTree& NewT)
{
    if (T == nullptr) { //����ǿ�������0
        return false;
    }
    NewT = new BiNode; //�����½��ռ�
    NewT->data = T->data; //���Ƹ����
    CopyBiTree(T->lchild, NewT->lchild); //�ݹ鸴��������
    CopyBiTree(T->rchild, NewT->rchild); //�ݹ鸴��������
    return true;
}

//������������
int Depth(BiTree& T) {
    if (T == nullptr) {
        return 0;
    }
    int m = Depth(T->lchild); 
    int n = Depth(T->rchild);
    if (m > n) { //�����������Ϊm��n�Ľϴ��߼�1
        return m + 1;
    }
    else {
        return n + 1;
    }
}

//��������Ľ����
int CountNode(BiTree& T) {
    if (T == nullptr) {
        return 0;
    }
    return CountNode(T->lchild) + CountNode(T->rchild) + 1;
}

//���������Ҷ�ӽ����
int CountONode(BiTree& T) {
    if (T == nullptr) {
        return 0;
    }
    if (T->lchild == nullptr && T->rchild == nullptr) {
        return 1;
    }
    return CountONode(T->lchild) + CountONode(T->rchild);
}

int main()
{


	system("pause");
	return 0;
}