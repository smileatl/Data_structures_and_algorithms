#include <iostream>
using namespace std;
#include <vector>

typedef int KeyType;
typedef int InfoType;

typedef struct {
	KeyType key;
	InfoType otherinfo;
}ElemType;

typedef struct BSTNode {
	ElemType data;
	BSTNode* lchild, * rchild;
}BSTNode, *BSTree;

//�����������ĵݹ�����㷨
BSTree SearchBST(BSTree& T, const KeyType& e) {
	if (!T || T->data.key == e) {
		return T;
	}
	else if (e < T->data.key) {
		return SearchBST(T->lchild, e);
	}
	else return SearchBST(T->rchild, e);
}

//�����������Ĳ���
void InsertBSTree(BSTree& T, const ElemType& e)
{
    //D������ֱ��ĳ��Ҷ�ӽ�����������������Ϊ��Ϊֹ���������ӦΪ��Ҷ�ӽ������ӻ��Һ���
    if (T == nullptr)
    {
        T = new BSTNode;
        T->data = e;
    }
    //L
    if (e.key < T->data.key)
        InsertBSTree(T->lchild, e);
    //R
    else if (e.key > T->data.key)
        InsertBSTree(T->rchild, e);
    //other���������У����ڲ���
    if (e.key == T->data.key)
        cerr << "already hava it" << endl;
}

//����������������
void CreatBSTree(BSTree& T)
{
    //�������У�Ҳ���Դ��βδ��룩
    cout << "input info about the tree" << endl;
    vector<ElemType> vec;
    ElemType input;
    //�Ƚ�һ��vector����
    while (cin >> input.key)
    {
        vec.push_back(input);
    }
    //���ò����㷨
    for (vector<ElemType>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        InsertBSTree(T, *it); //����������һȡ��Ԫ�أ����뵽������������
    }
}

int main()
{


	system("pause");
	return 0;
}