#include <iostream>
using namespace std;

typedef struct Dulnode {
	int data;
	Dulnode* prior, * next;
}*DulLinkList;

void InitList(DulLinkList& L) {
	L = new Dulnode;
	L->prior = nullptr;
	L->next = nullptr;
}

void CreatListHead(DulLinkList& L, size_t n) {
	for (int i = 0; i < n; i++) {
		Dulnode* p = new Dulnode;
		cin >> p->data;
		p->prior = L;
		p->next = L->next;
		L->next = p;
	}
}

void CreateListTail(DulLinkList& L, size_t n) {
	Dulnode* r = L;
	for (int i = 0; i < n; i++) {
		Dulnode* p = new Dulnode;
		cin >> p->data;
		p->prior = r;
		p->next = r->next;
		r->next = p;
		r = p;
	}
}

bool ListInsert_Dul(DulLinkList& L, int i, const int& e) {
	Dulnode* p = L->next;
	int j = 1;
	while (p->next && j < i) {
		j++;
		p = p->next;   //指向i个结点
	}
	if (j < i || j < 1) {
		cerr << "out of range" << endl;
		return false;
	}

	Dulnode* s = new Dulnode;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;

	return true;
}

bool ListErase_Dul(DulLinkList& L, const int i) {
	Dulnode* p = L->next;
	int j = 1;
	while (p->next && j < i) {
		j++;
		p = p->next;   //指向i个结点
	}
	if (j < i || j < 1) {
		cerr << "out of range" << endl;
		return false;
	}

	p->prior->next = p->next;
	if (p->next) {
		p->next->prior = p->prior;
	}
	delete p;
	return true;
}

int main()
{


	system("pause");
	return 0;
}