#include <bits/stdc++.h>
using namespace std;

int main() 
{
	string s;
	cin>>s;
    //可以正过来循环然后存入数组,然后再倒过来存入数组(这里要用到string数组)
	//这里有个问题,正着的子串可以有好几个开头,那就内层循环,j做加数
	vector<string>zheng;
	for(int i=0;i<s.size();i++)
	{
		string ss;
		for(int j=0;i+j<s.size();j++)
		{
			ss+=s[i+j];
			zheng.push_back(ss);
		}
	} 
//	cout<<zheng[0]<<zheng[4];
	reverse(s.begin(),s.end());
	vector<string>dao;
	for(int i=0;i<s.size();i++)
	{
		string ss;
		for(int j=0;i+j<s.size();j++)
		{
			ss+=s[i+j];
			dao.push_back(ss);
		}
	}
//	cout<<dao[0]<<dao[4];
//cout<<zheng[0]<<dao[5];
	//然后再根据正着的数组一一循环倒过来的数组,这个时候初始化一个max,然后再根据s.size来赋值
	int max=0;
	for(int i=0;i<zheng.size();i++)
	{
		for(int j=0;j<dao.size();j++)
		{
			if(zheng[i]==dao[j])
			{
				if(zheng[i].size()>max)
				max=zheng[i].size();
			}
		}
	}
	cout<<max;
}
