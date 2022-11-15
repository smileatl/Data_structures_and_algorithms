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

//二叉排序树的递归查找算法
BSTree SearchBST(BSTree& T, const KeyType& e) {
	if (!T || T->data.key == e) {
		return T;
	}
	else if (e < T->data.key) {
		return SearchBST(T->lchild, e);
	}
	else return SearchBST(T->rchild, e);
}

//二叉排序树的插入
void InsertBSTree(BSTree& T, const ElemType& e)
{
    //D，查找直至某个叶子结点的左子树或右子树为空为止，则插入结点应为该叶子结点的左孩子或右孩子
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
    //other，树中已有，不在插入
    if (e.key == T->data.key)
        cerr << "already hava it" << endl;
}

//二叉排序树的生成
void CreatBSTree(BSTree& T)
{
    //输入序列（也可以从形参传入）
    cout << "input info about the tree" << endl;
    vector<ElemType> vec;
    ElemType input;
    //先建一个vector容器
    while (cin >> input.key)
    {
        vec.push_back(input);
    }
    //调用插入算法
    for (vector<ElemType>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        InsertBSTree(T, *it); //从容器中逐一取出元素，插入到二叉排序树中
    }
}

int main()
{


	system("pause");
	return 0;
}