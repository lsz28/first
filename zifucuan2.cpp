#include<iostream>
using namespace std;
int main()
{
	char ch;
	while(cin>>ch)
	{
		if(ch>='a'&&ch<='z')
		{
			ch-=32;
		}
		
		cout<<ch;
	}
	char b;
	cin>>b;
	if(b=='h')
	cout<<"hhh";
return 0;
}
