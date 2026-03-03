#include<bits/stdc++.h>
using namespace std;
int main()
{
	//存入数据,算重复次数,注意从1开始循环 
	//如果数据相等就输出0 
	int m,k,n;
	cin>>n>>m>>k;
	vector<int>arr(n+1,0);
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	//给数组排个序
	sort(arr.begin(),arr.end()); 
	if(n==m*k)
	{
		cout<<"0";
		return 0; 
	}
	//i是数据坐标,建一个数组,数据[i]作为数组坐标算重复次数
	vector<int>chongfu(n+1,0);
	for(int i=1;i<=n;i++)
	{
		chongfu[arr[i]]++;
	}
	//再建一个根据重复次数的数组,等于k就输出k
	
	//如果小于k,就循环输出,i=k-数组 ,创一个数组接受答案,再sort输出;
	
//	cout<<chongfu[4];
	for(int i=1;i<=m;i++)
	{
		if(chongfu[i]<k)
		{
			vector<int>ans; 
			cout<<i<<" ";
			for(int j=k;j>chongfu[i];j--)
			{
				ans.push_back(j);
			}
			sort(ans.begin(),ans.end());
			for(int j=0;j<ans.size();j++)
			{
				if(j<ans.size()-1)
				cout<<ans[j]<<" ";
				else
				cout<<ans[j]<<'\n';
			}
		}
	}
}
