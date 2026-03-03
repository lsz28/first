//goto:直接跳到指定的一行 

#include<iostream>
using namespace std;
int main()
{
	cout<<"1";
	cout<<"2";
	goto flag;
	cout<<"3";
	cout<<"4";
	flag:
	cout<<"5";
return 0;
}
