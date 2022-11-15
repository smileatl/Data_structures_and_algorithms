#include <iostream>
using namespace std;

typedef struct Data {
	int coef;
	int index;
}Data;

typedef struct Lnode {
	Data data;//结点的数据域
	Lnode* next;//结点的指针域
}Lnode, * LinkList;

void SPO_II(LinkList& La, LinkList& Lb, LinkList& Lc) {
	Lnode* pa = La->next;
	Lnode* pb = Lb->next;
	Lc = La;
	Lnode* pc = Lc;
	while (pa && pb) {
		if (pa->data.index < pb->data.index) {
			pc->next = pa;
			pc = pc->next;
			pa = pa->next;
		}
		else if (pa->data.index > pb->data.index) {
			pc->next = pb;
			pc = pc->next;
			pb = pb->next;
		}
		else if (pa->data.index == pb->data.index) {
			pa->data.coef += pb->data.coef;
			pc->next = pa;
			pc = pc->next;
			pa = pa->next;
			pb = pb->next;
		}
	}
	pc->next = (pa ? pa : pb);
	delete Lb;
}

int main()
{


	system("pause");
	return 0;
}