#include <iostream>
using namespace std;
 
void func()
{
	cout << "func的调用" << endl;
}
 
void func(int a) //参数个数不同 
{
	cout << "func(int a)的调用" << endl;
}
 
//int func(int a)	//函数返回值不同不可以作为重载条件 
//{
//	return a;
//}
 
void func(double a)	//参数类型不同 
{
	cout << "func(double a)的调用" << endl;
}
 
void func(int a, double b)
{
	cout << "func(int a, double b)" << endl;
}
 
void func(double a, int b)	//参数顺序不同 
{
	cout << "func(double a, int b)" << endl;
}
 
int main()
{
	func();
	func(10);
	func(3.14);
	func(10, 3.14);
	func(3.14, 10);
	
	return 0;
}

//函数重载满足条件：
//
//在同一个作用域下
//函数名相同
//函数参数类型不同，或者个数不同，顺序不同



//1：引用不能作为重载条件

//2.引用作为函数参数const可以作为重载条件
