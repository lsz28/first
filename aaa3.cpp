#include<bits/stdc++.h>
using namespace std;
int main()
{
	//输入字符串
	string s;
	cin>>s;
	//然后写一个judge[]=true, 下标和字符串一一对应
	vector<bool>judge(s.size(),true);
	//开始循环寻找星号,然后令它和前面的一个不为true的为false(这里用到向前循环 记得要break) 
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='*')
		{
			judge[i]=false;
			for(int j=i-1;j>=0;j--)
			{
				if(judge[j]==true&&s[j]!='*')
				{
					judge[j]=false;
//					cout<<judge[2];
					break;
				}
			}
		}
	}
//	cout<<judge[1]<<judge[2];
	for(int i=0;i<judge.size();i++)
	{
		if(judge[i])
		cout<<s[i];
	}
	//最后循环下标为true的值 
} 
