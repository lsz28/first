#include<iostream>
using namespace std;
int main()
{
	int n;
	int guo[1000];
	for(int i=0;i<n;i++)
	{
		cin>>guo[i];
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(guo[j]>guo[j+1])
			{
				int temp=guo[j];
				guo[j]=guo[j+1];
				guo[j+1]=temp;
			}
		}
	}
	int hebing[1000]={0};
	hebing[0]=guo[0]+guo[1];
	for(int i=1;i<n-1;i++)
	{
		hebing[i]=hebing[i-1]+guo[i+1];
	}
	cout<<hebing[n-1]<<endl;
	
return 0;
}
