//while

#include<iostream>
using namespace std;
int main()
{
	int num;
	while(num<10)//注意不要死循环 
	             //while的循环条件是先判断括号里面的条件是否是真,如果是真就继续循环,如果是假就停 
	{
		cout<<num<<endl;
		num++;
	}
return 1;
}
