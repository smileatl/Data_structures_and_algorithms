#include <iostream>
using namespace std;

//存储结构-记录序列以顺序表存储
#define MAXSIZE 20 //设记录不超过20个

typedef int KeyType; //设关键字为整型量(int型)
typedef int InfoType;

typedef struct { //定义每个记录（数据元素）的结构
	KeyType key; //关键字
	InfoType otherinfo; //其他数据项
}RedType; //Record Type
 
typedef struct { //定义顺序表的结构
	RedType r[MAXSIZE + 1]; //存储顺序表的向量
							//r[0]一般作哨兵或缓冲区
	int length; //顺序表的长度
}SqList;



int main()
{


	system("pause");
	return 0;
}