/*一.数据类型
整型
1.short 2字节 -32768--32767 五位 
2.int 4字节 -2147483648-- 十位 
3.long 4字节 -2147483648 十位 
4.long long 8字节 -9223372036854775808--*/ 十九位 

#include<iostream>
using namespace std;

int main()
{
	//利用sizeof求出数据类型占用内存大小
	//语法：sizeof(数据类型/变量)
	
	short num1 = 10;
	//cout<<"short占用内存空间为："<<sizeof(short)<<endl;(这个也可以)
	cout<<"short占用内存空间为："<<sizeof(num1)<<endl;
	
	int num2=10;
	cout<<"int占用  内存空间为："<<sizeof(num2)<<endl;
	
	float num3=3.14f;//这里加了f是因为如果不加系统默认是double
	cout<<"Π="<<num3<<endl;
	cout<<"float占用内存空间为"<<sizeof(num3)<<endl;
	
	double num4=3.141;
	cout<<"Π="<<num4<<endl;
	cout<<"double占用内存空间为"<<sizeof(num4)<<endl;
	
	//科学计数法
	float num5=3e2;//3*10^2;
	cout<<"num5="<<num5<<endl;
	
	float num6=3e-2;//3*10^-2;
	cout<<"num6="<<num6<<endl;
	
	
	return 0;
}

//实型（浮点型）：用于表示小数
//1.单精度float  4字节 7位有效数字
//2.双精度double 8字节 15-16有效数字
//默认输出一个小数，显示6位小数
#include<iostream>
using namespace std;

/*int main()
{
	float num1=3.14f;
	cout<<"Π="<<num1<<endl;
	
	return 0;
}搞不了两个函数*/
