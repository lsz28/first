#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>shumu(n);
	for(int i=0;i<n;i++)
	{
		cin>>shumu[i];
	}
	sort(shumu.begin(),shumu.end());
	int jia[10000]={0};
	jia[0]=shumu[0]+shumu[1];
	for(int i=1;i<n-1;i++)
	{
		jia[i]+=jia[i-1]+shumu[i+1];
	}
	int sum=0;
	for(int i=0;i<n-1;i++)
	{
		sum+=jia[i];
	}
	cout<<sum<<endl;
}
