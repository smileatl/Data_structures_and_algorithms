//#include <iostream>
//using namespace std;
//
//typedef struct StackNode {
//	int data;
//	StackNode* next;
//}*LinkStack;
//
//void InitStack(LinkStack& S) {
//	S = new StackNode;
//	S->next = nullptr;
//	S->data = 0;
//}
//
//void Push(LinkStack& S, const int& e) {
//	StackNode* temp = new StackNode;
//	temp->data = e;
//	temp->next = S->next;
//	S->next = temp;
//	S->data++;
//}
//
//void Pop(LinkStack& S, int& e) {
//	StackNode* p = S->next;
//	e = p->data;
//	S->next = p->next;
//	S->data--;
//	delete p;
//}
//
//void CreateStack(LinkStack& S, int n) {
//	int input;
//	for (int i = 0; i < n; i++) {
//		cin >> input;
//		Push(S, input);
//	}
//}
//
//int StackLength(LinkStack& S) {
//	return S->data;
//}
//
//bool ClearStack(LinkStack& S) {
//	if (!(S->next)){
//		cerr<<"empty Stack"<<endl;
//		return false;
//	}
//	StackNode* q, * p = S->next;
//	while (p) {
//		q = p;
//		p = p->next;
//		delete p;
//	}
//	S->data = 0;
//	S->next = nullptr;
//	return true;
//}
//
//bool DestroyStack(LinkStack& S) {
//	while (S) {
//		StackNode* temp = S;
//		S = S->next;
//		delete temp;
//	}
//	return true;
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