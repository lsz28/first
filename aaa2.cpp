#include<bits/stdc++.h>
using namespace std;
int main()
{
	//输入,前n-1为string srr[n-2],后一个为srr[n-1]
	int n;
	cin>>n;
	vector<string>srr;
	string s;
	while(cin>>s)
	{
		srr.push_back(s);
	}
	//双层循环,拼接字符串数组,然后拼接后跟s相等sum+1,s是在循环初始化
    int sum=0;
	for(int i=0;i<n-1;i++)
	{
		
		for(int j=0;j<n-1;j++)
		{
			if(i!=j)
			{
			string ss=srr[i];
			ss+=srr[j];
			if(ss==srr[n-1])
			sum++;
			} 
		}
	 } 
	 cout<<sum;
} 

