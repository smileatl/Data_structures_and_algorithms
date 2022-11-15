#include <iostream>
using namespace std;

//递归算法

//二叉树的定义
typedef struct BiNode {
	int data;
	BiNode* lchild, * rchild;
}*BiTree;


//二叉树的先序遍历DLR
bool PreOrderTraverse(BiTree& T){
    if (T == nullptr)
    {
        return true;
    }
    //访问根结点
    visit(T);
    //递归遍历左孩子
    PreOrderTraverse(T->lchild);
    //递归遍历右孩子
    PreOrderTraverse(T->rchild);
    return true;
}

//二叉树的中序遍历LDR
bool InOrderTraverse(BiTree& T)
{
    if (T == nullptr)
    {
        return true;
    }
    //第一步：访问左孩子
    InOrderTraverse(T->lchild);
    //第二步：访问根结点
    visit(T);
    //第三步：访问右孩子
    InOrderTraverse(T->rchild);
    return true;
}

//二叉树的后序遍历
bool PostOrderTraverse(BiTree& T)
{
    if (T == nullptr)
    {
        return true;
    }
    //第一步：访问左孩子
    PostOrderTraverse(T->lchild);
    //第二步：访问右孩子
    PostOrderTraverse(T->rchild);
    //第三步：访问根结点
    visit(T);
    return true;
}

//二叉树的建立（DLR先序遍历，递归算法）
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

//二叉树的复制
bool CopyBiTree(const BiTree& T, BiTree& NewT)
{
    if (T == nullptr) { //如果是空树返回0
        return false;
    }
    NewT = new BiNode; //申请新结点空间
    NewT->data = T->data; //复制根结点
    CopyBiTree(T->lchild, NewT->lchild); //递归复制左子树
    CopyBiTree(T->rchild, NewT->rchild); //递归复制右子树
    return true;
}

//求二叉树的深度
int Depth(BiTree& T) {
    if (T == nullptr) {
        return 0;
    }
    int m = Depth(T->lchild); 
    int n = Depth(T->rchild);
    if (m > n) { //二叉树的深度为m与n的较大者加1
        return m + 1;
    }
    else {
        return n + 1;
    }
}

//求二叉树的结点数
int CountNode(BiTree& T) {
    if (T == nullptr) {
        return 0;
    }
    return CountNode(T->lchild) + CountNode(T->rchild) + 1;
}

//求二叉树的叶子结点数
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