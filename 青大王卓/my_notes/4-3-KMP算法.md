# KMP算法

![1667355268294](4-KMP算法.assets/1667355268294-1667355268748.png)

![1667349806705](4-KMP算法.assets/1667349806705-1667349807086.png)

前缀

![1667355601095](4-KMP算法.assets/1667355601095-1667355601271.png)

后缀

![1667355633559](4-KMP算法.assets/1667355633559-1667355633773.png)



k-1是1，所以k是2

![1667355909019](4-KMP算法.assets/1667355909019-1667355909342.png)



k-1是2，所以k是3

![1667356199739](4-KMP算法.assets/1667356199739-1667356199992.png)



最终结果

![1667356405438](4-KMP算法.assets/1667356405438-1667356405668.png)



![1667356483224](4-KMP算法.assets/1667356483224-1667356483539.png)

![1667356554567](4-KMP算法.assets/1667356554567-1667356554770.png)

j=4，a字符跟b字符不匹配，那p串中与a相同的字符跟b也肯定不匹配

![1667358297053](4-KMP算法.assets/1667358297053-1667358297315.png)

![1667358780199](4-KMP算法.assets/1667358780199-1667358780813.png)









![1667351609514](4-KMP算法.assets/1667351609514-1667351609842.png)

![1667351632325](4-KMP算法.assets/1667351632325-1667351632641.png)

```cpp
int match ( char* P, char* T ) { //KMP算法
	int* next = buildNext ( P ); //极造next表
	int n = ( int ) strlen ( T ), i = 0; //文本串指针
	int m = ( int ) strlen ( P ), j = 0; //模式串指针
	while ( j < m && i < n ) //自左向右逐个比对字符
		if ( 0 > j || T[i] == P[j] ) //若匹配，或P已移出最左侧（两个判断的次序不可交换）
			{ i ++; j ++; } //则转到下一字符
		else //否则
			j = next[j]; //模式串右秱（注意：文本串丌用回退）
	delete [] next; //释放next表
	return i - j;
}
```

![1667354647517](4-KMP算法.assets/1667354647517-1667354647720.png)

![1667354663999](4-KMP算法.assets/1667354663999-1667354664257.png)