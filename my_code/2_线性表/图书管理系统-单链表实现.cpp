#include <iostream>
using namespace std;

typedef struct Book {
	string isbn;
	string name;
	float price;
};
struct Lnode {
	Book data;
	Lnode* next;
}*LinkList;

istream &read(istream& in, Book& rhs) {
	in >> rhs.isbn;
	in >> rhs.name;
	in >> rhs.price;
	return in;
}

ostream &print(ostream &out,Book &rhs){
	out << rhs.isbn << " "
		<< rhs.name << " "
		<< rhs.price << endl;
	return out;
}

int main()
{
	

	system("pause");
	return 0;
}