#include <iostream>
using namespace std;

typedef struct Lnode {
	int data;//结点的数据域
	Lnode* next;//结点的指针域
}Lnode, * LinkList;

bool InitList(LinkList& L) {
	L = new Lnode;
	L->next = nullptr;
	return true;
}

void CreateLIst(LinkList& L, int n) {
	for (int i = 0; i < n; i++) {
		Lnode* p = new Lnode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

void CreateListTail(LinkList& L, int n) {
	Lnode* r = new Lnode;
	for (int i = 0; i < n; i++) {
		Lnode* p = new Lnode;
		cin >> p->data;
		p->next = nullptr;
		r->next = p;
		r = p;
	}
}

bool IsEmpty(LinkList& L) {
	if (L->next) {
		return false;
	}
	else {
		return true;
	}
}

bool DestroyList(LinkList& L) {
	//判断链表是否为空
	if (IsEmpty(L))
	{
		cerr << "empty List!" << endl;
		return false;
	}
	while (L) {
		auto p = L;
		L = L->next;
		delete p;
	}
	return true;
}

int ListLength(const LinkList& L) {
	int i = 0;
	Lnode* p = L->next;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

bool GetElem(const LinkList& L, int i, int &e) {
	if (i < 0) {
		cerr << "out of range" << endl;
		return false;
	}
	int j = 1;
	Lnode* p = L->next;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i) {
		return false;
	}
	e = p->data;
	return true;
}

Lnode* LocateElem(LinkList& L, int e) {
	Lnode* p = L->next;
	while (p && p->data != e) {
		p = p->next;
	}
	return p;
}

int LocateElem(LinkList L, int e) {
	Lnode* p = L->next;
	int j = 1;
	while (p && p->data != e) {
		p = p->next;
		j++;
	}
	if (p) {
		return j;
	}
	else {
		return 0;
	}
}

bool InsertList(LinkList& L, int i, int e) {
	int j = 0;
	Lnode* p = L;
	
	while(p && j<i-1){
		p = p->next;  //指向第i-1个结点
		j++;
	}
	if (!p || j > i - 1) {
		return false;
	}
	Lnode* insert = new Lnode;
	insert->data = e;
	insert->next = p->next;
	p->next = insert;
	return true;
}

bool EraseList(LinkList& L, int i) {
	Lnode* p = L;
	int j = 0;
	while (p->next && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!(p->next) || i < 0) {
		cerr << "out of range" << endl;
		return false;
	}
	Lnode* q = p->next;
	p->next = p->next->next;
	delete q;
	return true;
}



int main()
{


	system("pause");
	return 0;
}