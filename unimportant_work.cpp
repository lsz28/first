#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int gift[n];
	for(int i=0;i<n;i++)
	{
		cin>>gift[i];
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(gift[i]==0)
		continue;
		else
		{
			if(gift[i]%4==0||gift[i]%7==0)
			{
				sum+=gift[i];
			}
		}
	}
	cout<<sum<<endl;
}



