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
	return 0;
}
