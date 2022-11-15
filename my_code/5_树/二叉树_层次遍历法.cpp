#include <iostream>
using namespace std;

#define MAXSIZE 100

//˳�����
struct SqQueue {
	int* elem;
	int front;
	int rear;
};

void InitSqQueue(SqQueue& Q) {
	Q.elem = new int[MAXSIZE];
	Q.front = Q.rear = 0;
}

//�������Ķ���
typedef struct BiNode {
	int data;
	BiNode* lchild, * rchild;
}*BiTree;

//�������Ĳ�α����㷨
void LevelOrder(BiTree& S) {
	SqQueue Q;
	InitSqQueue(Q);

	BiTree p;
	PushQueue(Q, S);
	while (!QueueEmpty(Q)) {
		Dequeue(Q, p); 
		cout << p->data << endl;
		if (p->lchild != nullptr) {
			PushQueue(Q, p->lchild);
		}
		if (p->rchild != nullptr) {
			PushQueue(Q, p->rchild);
		}
	}
}


int main()
{


	system("pause");
	return 0;
}
