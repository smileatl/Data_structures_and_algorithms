#include <iostream>
using namespace std;

struct Qnode {
	int data;
	Qnode* next;
};

struct LinkQueue {
	Qnode* front;
	Qnode* rear;
};

void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new Qnode;
	Q.front->data = 0;
	Q.rear->next = nullptr;
}

void InsertQueue(LinkQueue& Q, const int& e) {
	Qnode* temp = new Qnode;
	temp->data = e;
	temp->next = nullptr;
	Q.rear->next = temp;
	Q.rear = temp;
	Q.front->data++;
}

void CreateQueue(LinkQueue& Q, const int n) {
	cout << "input msg" << endl;
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		InsertQueue(Q, input);
	}
}

bool EraseQueue(LinkQueue& Q) {
	if (Q.front->next == nullptr) {
		cerr << "empty Queue" << endl;
		return false;
	}
	Qnode* p = Q.front->next;
	Q.front->next = p->next;
	delete p;
	Q.front->data--;
	return true;
}

void PrintQueue(LinkQueue& Q) {
	Qnode* p = Q.front->next;
	while (p) {
		cout << p->data << endl;
		p = p->next;
	}
}

int main()
{


	system("pause");
	return 0;
}