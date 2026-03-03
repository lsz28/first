//运算符
//加减乘除 取余 前后置递减 前后置递增 
#include <iostream>
using namespace std;
int main()
{
	int a1=4;
	int a2=2;
	cout<<a1+a2<<endl;
	//加减乘*基本没有什么区别
	
	int a3=6;
	int a4=4;
	cout<<a3/a4<<endl;//整数相除保留只整数 
	
	float b=3.6;
	float c=1.3;
	cout<<b/c<<endl;//两个小数相除可以出现小数
	
	int d=5;
	float e=2.6;
	cout<<d/e<<endl; //整数除小数也可以出小数 
	
	int f=10;
	int g=20;
	cout<<f%g<<endl;
	/*两个小数不能取余*/
	
	//前置递增
	int as=10;
	++as;
	cout<<as<<endl;
	
	//后置递增
	int ad=11;
	ad++;
	cout<<ad<<endl;
	
	/*前置递增和后置递增的区别*/
	
	//前置递增是先使变量加一再计算表达式,毕竟加号在前,那肯定要先加1啦 
	int af=10;
	int ba=++af;//表达式 
	cout<<af<<endl;
	cout<<ba<<endl;//11
	
	//后置递增是先算表达式再使变量加一
	int ag=10;
	int bs=ag++;
	cout<<ag<<endl;
	cout<<bs<<endl; //10
	
	//前置递减和后置递减也一样 
	 
     
	
	
	
	
	return 1;
 } 
