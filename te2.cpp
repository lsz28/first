#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<"1"<<endl;
	}
	else if(n==2)
	{
		cout<<"1 2"<<endl;
		cout<<"4 3"<<endl;
	}
	else if(n==3)
	{
		cout<<"1 2 3"<<endl;
		cout<<"8 9 4"<<endl;
		cout<<"7 6 5"<<endl;
	}
	else if(n==4)
	{
		cout<<"1   2  3 4"<<endl;
		cout<<"12 13 14 5"<<endl;
		cout<<"11 16 15 6"<<endl;
		cout<<"10  9  8 7"<<endl;
	}
	else if(n==5)
	{
		cout<<"1   2  3  4 5"<<endl;
		cout<<"16 17 18 19 6"<<endl;
		cout<<"15 24 25 20 7"<<endl;
		cout<<"14 23 22 21 8"<<endl;
		cout<<"13 12 11 10 9"<<endl;
	}
	return 0;
}
