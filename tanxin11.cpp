#include<iostream>
#include<cmath>
using namespace std;
//struct jinbi
//{
//	double w;
//	double zongjia;
//	double danjia=zongjia/w;
//};
int main()
{
	int n,t;
	cin>>n>>t;
//	 jinbi[100];
    double w[100];
    double zongjia[100];
    double danjia[100];
	for(int i=0;i<n;i++)
	{
		cin>>w[i]>>zongjia[i];
		danjia[i]=zongjia[i]/w[i];
	}
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(danjia[j]<danjia[j+1])
			{
			double temp=danjia[j];
			danjia[j]=danjia[j+1];
			danjia[j+1]=temp;
			
			double temp1=w[j];
			w[j]=w[j+1];
			w[j+1]=temp1;
			
//			double temp2=zongjia[j];
//			danzongjia[j]=danjia[j+1];
//			danjia[j+1]=temp;
			}	
		}
	}
	double sum;
	for(int i=0;i<n;i++)
	{
		if(w[i]<=t)
		{
			sum+=w[i]*danjia[i];
			t-=w[i];
		}
		else
		{
			sum+=t*danjia[i];
			break;
		}
	}
	cout<<fixed<<set<<precision(2)<<sum<<endl;
return 0;
}
