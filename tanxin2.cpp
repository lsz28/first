#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	cin>>n;
	double arr[1000]; 
	int shunxu[1000];
	for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    	shunxu[i]=i+1;
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				double temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				
				int tem=shunxu[j];
				shunxu[j]=shunxu[j+1];
				shunxu[j+1]=tem;
				
			}
		}
	}
	double sum[1000]={0};
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			sum[i]+=arr[j];
		}
	}
	double summ;
	for(int i=0;i<n;i++)
	{
		summ+=sum[i];
	}
	double fenbie=summ/n;
	for(int i=0;i<n;i++)
	{
		if(i!=n-1)
		cout<<shunxu[i]<<" ";
		else
		cout<<shunxu[i]<<'\n';
	}
	cout<<fixed<<setprecision(2)<<fenbie<<'\n';
return 0;
}
