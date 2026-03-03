#include<iostream>
using namespace std;
int main()
{
	int days[48]=
	{
		31,28,31,30,31,30,31,31,30,31,30,31,
		31,29,31,30,31,30,31,31,30,31,30,31,
		31,28,31,30,31,30,31,31,30,31,30,31,
		31,28,31,30,31,30,31,31,30,31,30,31
	};
	int n;
	cin>>n;
	int input[24];
	for(int i=0;i<n;++i)
	{
		cin>>input[i];
	}
	bool isMatch=false;
	for(int i=0;i<=24;i++)
	{
		bool match=true;
		for(int j=0;j<n;j++)
		{
			if(days[i+j]!=input[j])
			{
				match=false;
				break;
			}
		}
		if(match)
		{
			isMatch=true;
			break;
		}
	}
	cout<<(isMatch?"Yes":"No")<<endl;
	return 0;
}
