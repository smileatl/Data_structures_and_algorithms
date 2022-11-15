#include <iostream>
using namespace std;
#include <vector>

struct SqStack {
    int* base;
    int* top;
    int stacksize;
};

//哈夫曼树的定义
typedef struct HNode {
	int weight;
	int parent, lchild, rchild;
}*HuffmanTree;

//哈夫曼树的初始化
void InitHTree(HuffmanTree& H, const int n)
{
    //哈夫曼树的存储结构为顺序存储
    //由哈夫曼树的构造过程得知，n个权重结点构造出的哈夫曼树具有2*n-1个结点
    //通常哈夫曼树的顺序存储结构下标从1开始计数，因此，如果我们使用数组实现的话
    //那么数组的长度应该是2*n
    H = new HNode[2 * n];
    for (int i = 1; i < 2 * n; ++i) //将2n-1个元素的lchild,rchild,parent置为0
    {
        H[i].parent = H[i].lchild = H[i].rchild = 0;//右结合律
    }
    int input;
    for (int i = 1; i <= n; ++i)
    {
        cin >> input;
        H[i].weight = input; //输入前n个元素的weight值
    }
}

//select算法
void Select(HuffmanTree& H, const int n, int& i1, int& i2) {
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        if (H[i].parent == 0) {
            vec.push_back(i);
        }
    }
    //找出最小的一个
    auto flag1 = vec.begin();
    for (auto it = vec.begin() + 1; it != vec.end(); it++) {
        if (H[*it].weight < H[*flag1].weight) {
            flag1 = it;
        }
    }
    i1 = *flag1;

    vec.erase(flag1);
    auto flag2 = vec.begin();
    for (auto it = vec.begin() + 1; it != vec.end(); it++) {
        if (H[*it].weight < H[*flag2].weight) {
            flag2 = it;
        }
    }
    i2 = *flag2;
}

//哈夫曼树的构造算法
void CreatHuffman(HuffmanTree& H, const int length)
{
    //第一步：对哈夫曼树进行初始化
    InitHTree(H, length);
    //第二步：找出当前森林中最小的两棵树，创建新树，并让原来的两个树作为新树的孩子
    for (int i = length + 1; i < 2 * length; ++i) //合并产生n-1个结点——构造Huffman树
    {
        int i1 = 0, i2 = 0;
        Select(H, i - 1, i1, i2);//重点是这个Select算法
        H[i].weight = H[i1].weight + H[i2].weight;//i的权值为左右孩子权值之和
        H[i1].parent = H[i2].parent = i; //表示从F中删除s1，s2
        H[i].lchild = i1; //s1，s2分别作为i的左右孩子
        H[i].rchild = i2;
    }
}

//哈夫曼编码算法
void HuffmanCode(HuffmanTree& H, const int n)
{
    //第一步：调用函数创建一个顺序存储结构的哈夫曼树，同上的函数一样
    CreatHuffman(H, n);
    //第二步：遍历哈夫曼树中每一个叶子结点，也即哈夫曼数组中的前n个元素
    for (int i = 1; i <= n; ++i)
    {
        int chd = i;
        int par = H[chd].parent;
        //自下而上得到哈夫曼编码，用栈来保存再合适不过了
        SqStack S;
        InitStack(S);
        while (par != 0) //从叶子结点开始向上回溯，直到根结点
        {
            H[par].lchild == chd ? /*左孩子，0进栈*/ Push(S, 0) : /*右孩子，1进栈*/ Push(S, 1);
            //继续向上回溯
            chd = par;
            par = H[chd].parent;
        }
        //出栈//黑框中打印编码
        while (!IsEmpty(S))
        {
            int out;
            Pop(S, out);
            cout << out;
        }
        cout << endl;
    }
}

int main()
{


	system("pause");
	return 0;
}