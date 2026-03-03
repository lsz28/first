//赋值运算符
//就是又让变量变了而已,说出了要改变的值 
#include<iostream>
using namespace std;
int main()
{
	int a=1;//这里int可以只写一次的原因是下面是对a的更改，但是已经定义过a了 
	a+=2;//就是a加数是2 
	cout<<a<<endl;
	/*-=一样的道理*/
	
	a=1;
	a*=2; 
	cout<<a<<endl;
	
	a=1;
	a/=2;
	cout<<a<<endl;
	
	a=10;
	a%=3;//a除2再取余数
	cout<<a<<endl; 
	
	
	return 1;
 } 
