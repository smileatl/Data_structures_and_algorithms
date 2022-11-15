#include <iostream>
using namespace std;

struct SqList {
	int* elem;
	int length;
};

void PolyOperate(SqList& L1, SqList& L2, SqList& L3) {
	for (int i = 0; i < L1.length && i < L2.length; i++) {
		L3.elem[i] = L1.elem[i] + L2.elem[i];
		L3.length += i;
	}
	if (L1.length < L2.length) {
		for (int j = L1.length; j < L2.length; j++) {
			L3.elem[j] = L2.elem[j];
			L3.length += 1;
		}
	}
	else {
		for (int j = L2.length; j < L1.length; j++) {
			L3.elem[j] = L1.elem[j];
			L3.length += 1;
		}
	}
}

int main()
{


	system("pause");
	return 0;
}