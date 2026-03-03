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
	vector<int>sum; 
	while(shumu.size()>1)
	{
		int sum1=(shumu[0]+shumu[1]);
		sum.push_back(sum1);
		shumu.erase(shumu.begin());
		shumu.erase(shumu.begin());
		shumu.push_back(sum1);
	    sort(shumu.begin(),shumu.end());
	}
	int last=0;
	for(int i=0;i<sum.size();i++)
	{
		last+=sum[i];
	}
	cout<<last<<'\n';
	return 0;
}
