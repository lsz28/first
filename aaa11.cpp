#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>shuju;
	int a;
	while(cin>>a)
	{
		shuju.push_back(a); 
	}
	if(n==m*k)
	{
		cout<<"0";
		return 0;
	}
	//m从1开始指人	
	vector<int>sum(m+1,0);//第m个人,然后sum就代表m人各自有几个数据 
	for(int i=0;i<shuju.size();i++)//i就代表人,人做下标,数据中的数字也做下标 
	{
		sum[shuju[i]]++;
	} 
	vector<bool>judge(m,false);
//	int last;//没测的项数 
    
	for(int i=1;i<=m;i++)//要对每个人的sum下手了
	{
		if(sum[i]==k)
		judge[i]=true;//就是数据都满了 
		else
		{
			judge[i]=false;
			cout<<i<<" ";
//			last=k-sum[i];
vector<int>answer;
			for(int j=k;j>sum[i];j--)
			{
				answer.push_back(j);
			}
			sort(answer.begin(),answer.end());
			for(int a=0;a<answer.size();a++)
			{
				cout<<answer[a];
				if(a<answer.size()-1)
				cout<<" ";
			}
			cout<<endl;
		}
	} 
//	bool judgee=true;//判断是否全满了 
//	for(int i=0;i<m;i++)
//	{
//		if(sum[i]<k)
//		{
//			judgee=false;
//			break;
//		}
//	}
//	if(n==)
//	cout<<"0"<<endl;
}

