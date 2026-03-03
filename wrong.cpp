#include<iostream>
using namespace std;
void swagg(int a,int b);
void swagg(int a,int b)
{
	int temp=a;
	a=b;
	b=temp;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
}

int main()
{
	int a=10;
	int b=20;
	swagg(a,b);
	system("pause");
return 0;
} 
