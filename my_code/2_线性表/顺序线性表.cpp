#include <iostream>
using namespace std;

#define MAXSIZE 100

struct SqList {
	int* elem;
	int length;
};

bool InitList(SqList& L) {
	L.elem = new int[MAXSIZE];
	if (!L.elem) {
		cerr << "error" << endl;
		return false;
	}

	L.length = 0;
	return true;
}

void DestroyList(SqList& L) {
	if (L.elem) {
		delete L.elem;
	}
}

void ClearList(SqList& L) {
	L.length = 0;
}

int ListLength(SqList& L) {
	return L.length;
}

bool IsEmpty(const SqList& L) {
	return static_cast<bool>(L.length);  //c++运算符，将一个表达式转换为某种类型，
						//但没有运行是类型检查来保证转换的安全

	if (L.length == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool GetElem(SqList& L, size_t i, int& e) {
	if (i<1 || i>MAXSIZE) {
		cerr << "out of range" << endl;
		return false;
	}
	e = L.elem[i - 1];
	return true;
}

int LocateList(SqList& L, const int& e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e) {
			return i + 1;
		}
	}
	return 0;
}

bool InsertList(SqList& L, int i, int e) {
	//判断线性表长度是否小于最大长度MAXSIZE
	if (L.length == MAXSIZE)
	{
		cerr << "can not insert!" << endl;
		return false;
	}
	if (i<0 || i>L.length)
	{
		cerr << "wrong insert position!" << endl;
		return false;
	}

	if (i <= L.length) {
		for (int p = L.length - 1; p >= i-1; p--) {
			L.elem[p+1]=L.elem[p];
		}
	}
	L.elem[i - 1] = e;
	L.length++;

	return true;
}

bool EraseList(SqList& L, const int& i) {
	//异常判断
	if (i<0 || i>L.length)
	{
		cerr << "wrong erase position!" << endl;
		return false;
	}
	if (L.length == 0)
	{
		cerr << "List has no length" << endl;
		return false;
	}

	for (int p = i; p < L.length; p++) {
		L.elem[p - 1] = L.elem[p];
	}
	L.length--;
	return true;
}



int main()
{
	/*for (int i = 0; i < 10; i++) {
		cout << i << endl;
	}*/

	system("pause");
	return 0;
}