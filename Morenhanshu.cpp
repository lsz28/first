#include <iostream>
using namespace std;
 
int text(int a, int b = 10, int c = 20)
{
	return a + b + c;
}
 
int main()
{
	cout << text(0) << endl;			//30
	cout << text(0, 20) << endl;		//40
	cout << text(0, 20, 40) << endl;	//60
	
	return 0;
}
//1.如果某个位置已经有了默认参数，那么这个位置之后的参数都应该有默认参数。
//2.如果声明有默认参数，实现不能有，实现有默认参数，声明不能有。
//3.当函数占位参数有默认参数时，可以不传入数值。

#include <iostream>
 
void text(int a, int)//占位参数, 函数的占位参数在传参时，必须传入数值
{
	cout << "this func" << endl;
}
 
int main()
{
	text(10, 20);
	
	return 0;
}
