#include <iostream>
using namespace std;
#include <vector>

struct SqStack {
    int* base;
    int* top;
    int stacksize;
};

//���������Ķ���
typedef struct HNode {
	int weight;
	int parent, lchild, rchild;
}*HuffmanTree;

//���������ĳ�ʼ��
void InitHTree(HuffmanTree& H, const int n)
{
    //���������Ĵ洢�ṹΪ˳��洢
    //�ɹ��������Ĺ�����̵�֪��n��Ȩ�ؽ�㹹����Ĺ�����������2*n-1�����
    //ͨ������������˳��洢�ṹ�±��1��ʼ��������ˣ��������ʹ������ʵ�ֵĻ�
    //��ô����ĳ���Ӧ����2*n
    H = new HNode[2 * n];
    for (int i = 1; i < 2 * n; ++i) //��2n-1��Ԫ�ص�lchild,rchild,parent��Ϊ0
    {
        H[i].parent = H[i].lchild = H[i].rchild = 0;//�ҽ����
    }
    int input;
    for (int i = 1; i <= n; ++i)
    {
        cin >> input;
        H[i].weight = input; //����ǰn��Ԫ�ص�weightֵ
    }
}

//select�㷨
void Select(HuffmanTree& H, const int n, int& i1, int& i2) {
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        if (H[i].parent == 0) {
            vec.push_back(i);
        }
    }
    //�ҳ���С��һ��
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

//���������Ĺ����㷨
void CreatHuffman(HuffmanTree& H, const int length)
{
    //��һ�����Թ����������г�ʼ��
    InitHTree(H, length);
    //�ڶ������ҳ���ǰɭ������С������������������������ԭ������������Ϊ�����ĺ���
    for (int i = length + 1; i < 2 * length; ++i) //�ϲ�����n-1����㡪������Huffman��
    {
        int i1 = 0, i2 = 0;
        Select(H, i - 1, i1, i2);//�ص������Select�㷨
        H[i].weight = H[i1].weight + H[i2].weight;//i��ȨֵΪ���Һ���Ȩֵ֮��
        H[i1].parent = H[i2].parent = i; //��ʾ��F��ɾ��s1��s2
        H[i].lchild = i1; //s1��s2�ֱ���Ϊi�����Һ���
        H[i].rchild = i2;
    }
}

//�����������㷨
void HuffmanCode(HuffmanTree& H, const int n)
{
    //��һ�������ú�������һ��˳��洢�ṹ�Ĺ���������ͬ�ϵĺ���һ��
    CreatHuffman(H, n);
    //�ڶ�������������������ÿһ��Ҷ�ӽ�㣬Ҳ�������������е�ǰn��Ԫ��
    for (int i = 1; i <= n; ++i)
    {
        int chd = i;
        int par = H[chd].parent;
        //���¶��ϵõ����������룬��ջ�������ٺ��ʲ�����
        SqStack S;
        InitStack(S);
        while (par != 0) //��Ҷ�ӽ�㿪ʼ���ϻ��ݣ�ֱ�������
        {
            H[par].lchild == chd ? /*���ӣ�0��ջ*/ Push(S, 0) : /*�Һ��ӣ�1��ջ*/ Push(S, 1);
            //�������ϻ���
            chd = par;
            par = H[chd].parent;
        }
        //��ջ//�ڿ��д�ӡ����
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