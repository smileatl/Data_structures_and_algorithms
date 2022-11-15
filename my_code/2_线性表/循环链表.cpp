#include <iostream>
using namespace std;

typedef struct CLnode {
	int data;
	CLnode* next;
}*CircList;

void InitList(CircList& L) {
	L = new CLnode;
	L->next = L;
}

//Ta¡¢Tb±íÊ¾Î²Ö¸Õë
CircList Connect(CircList Ta, CircList Tb) {
	CLnode* p = Ta->next;
	p = Ta->next;
	Ta->next = Tb->next->next;
	delete Tb->next;
	Tb->next = p;
	return Tb;
}

int main()
{


	system("pause");
	return 0;
}