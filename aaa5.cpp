#include <bits/stdc++.h>
using namespace std;
int main() 
{
    //打算一篇一篇得处理
	//先输入前两位
	int n,m;
	cin>>n>>m;
	vector<int>sum(m+1,0);
	vector<int>ans(m+1,0);
	//然后for循环文章,在文章里面再输入数据,然后放到数组里面
    for(int i=0;i<n;i++)
    {
    	int a;
    	cin>>a;
    	vector<int>arr(a,0);
    	for(int j=0;j<a;j++)
    	{
    		cin>>arr[j];
		}
		vector<bool>judge(m+1,false);
		for(int j=0;j<a;j++)
		{
			for(int num=1;num<=m;num++)
			{
				if(arr[j]==num)
				{
					sum[num]++;
					judge[num]=true;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(judge[j]==true)
			ans[j]++;
		}
	}
//	cout<<sum[1]<<ans[1];
	//循环数组,然后再循环数字,如果等一数字,sum加1,而且judge[i]]为true
	//再次循环true,如果是true,ans+1 
	//输出ans和sum (ans,sum作为全局变量吧) 
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" "<<sum[i]<<endl;
	}
}
