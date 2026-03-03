#include <iostream>
 
void text(int a, int b = 10)
{
	cout << "text(int a, int b = 10)" << endl;
}
 
void text(int a)
{
	cout << "text(int a)" << endl;
}
 
int main()
{
	text(10);	//不能发生重载
	text(10, 20);	//可以发送重载
	
	return 0; 
}
