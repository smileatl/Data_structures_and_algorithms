//#include <iostream>
//using namespace std;
//
//#define MAXSIZE 100
//
//struct SqQueue {
//	int* elem;
//	int front;
//	int rear;
//};
//
//void InitQueu(SqQueue& Q) {
//	Q.elem = new int[MAXSIZE];
//	Q.front = Q.rear = 0;
//}
//
//bool IsEmpty(SqQueue& Q) {
//	if (Q.front == Q.rear) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//bool IsFull(SqQueue& Q) {
//	//少用一个元素空间的方式
//	auto rear_next = (Q.rear + 1) % MAXSIZE;
//	if (rear_next == Q.front) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//bool InsertQueue(SqQueue& Q, const int& e) {
//	if (IsFull(Q)) {
//		cerr << "out of Queue" << endl;
//		return false;
//	}
//	Q.elem[Q.rear] = e;
//	Q.rear = (Q.rear + 1) % MAXSIZE;
//	return true;
//}
//
//void CreateQueue(SqQueue& Q, const int n) {
//	cout << "input msg" << endl;
//	int input;
//	for (int i = 0; i < n; i++) {
//		cin >> input;
//		InsertQueue(Q, input);
//	}
//}
//bool EraseQueue(SqQueue &Q){
//	if (IsEmpty(Q)) {
//		cerr << "no elem to erase" << endl;
//		return false;
//	}
//	//e = Q.elem[Q.front];
//	Q.front = (Q.front) % MAXSIZE;
//	return true;
//}
//
//
//int GetLength(SqQueue  &Q) {
//	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
//	
//}
//
//void PrintQueue(SqQueue& Q) {
//	cout << "Queue:" << endl;
//	for (auto i = Q.front; i != Q.rear; i = (i + 1) % MAXSIZE) {
//		cout << Q.elem[i] << endl;
//	}
//}
//
//
//
//int main()
//{
//
//
//	system("pause");
//	return 0;
//}