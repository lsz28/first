#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,max;
//	int tang[1000];
    cin>>n>>max;
    vector <int> tang(n);
	for(int i=0;i<n;i++)
	{
		cin>>tang[i];
	}
//	cout<<"hhh";
	int sum=0;
	for(int i=0;i<n-1;i++)
	{
		if(tang[i]+tang[i+1]>max)
		{
			sum+=(tang[i]+tang[i+1])-max;
			tang[i+1]-=(tang[i]+tang[i+1])-max;
			
		}
	}
	cout<<sum<<endl;
return 0;
}
