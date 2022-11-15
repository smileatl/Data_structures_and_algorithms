//#include <iostream>
//using namespace std;
//
//#define MAXSIZE 100
//
//struct Sqstack {
//	int* base;
//	int* top;
//	int stacksize;
//};
//
//bool InitStack(Sqstack& S) {
//	S.base = new int[MAXSIZE];
//	if (!S.base) {
//		cerr << "failed to get memory" << endl;
//		return false;
//	}
//	S.top = S.base;
//	S.stacksize = MAXSIZE;
//	return true;
//}
//
//bool Push(Sqstack& S, int& e) {
//	if ((S.top - S.base) == S.stacksize) {
//		cerr << "full of stack" << endl;
//		return false;
//	}
//	*(S.top) = e;
//	S.top++;
//}
//
//bool CreateStack(Sqstack& S, int n) {
//	for (int i = 0; i < n; i++) {
//		int input;
//		cin >> input;
//		if (!Push(S, input)) {
//			cerr << "error happend at-" << i << endl;
//			return false;
//		}
//	}
//	return true;
//}
//
//bool IsEmpty(Sqstack& S) {
//	if (S.base == S.top) {
//		return true;
//	}
//	else {
//		return true;
//	}
//}
//
//int StackLength(Sqstack& S) {
//	return static_cast<int>(S.top - S.base);
//}
//
//void DestroyStack(Sqstack& S) {
//	if (S.base) {
//		delete[] S.base;  //S.base在堆区开辟的数组
//		S.stacksize = 0;
//		S.base = S.top = nullptr;
//	}
//}
//
//int main()
//{
//
//
//	system("pause");
//	return 0;
//}