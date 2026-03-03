#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	vector<int>chongfushu(128,0);
	
	for(int i=0;i<s.size();i++)
	{
	    for(int j=i;j<s.size();j++)
	    {
	    	if(s[i]==s[j])
	    	{
	    		chongfushu[i]+=1;
			}
		}
	}
	int max;
	int min;
	max=chongfushu[0];
	min=chongfushu[0];
	for(int i=0;i<s.size();i++)
	{
		if(max<chongfushu[i])
		{
			max=chongfushu[i];
		}
		if(min>chongfushu[i])
		{
			min=chongfushu[i];
		}
		 
	}
	int jian=max-min;
	bool judge=false;
	if(jian==2)
	{
		cout<<"Lucky Word"<<endl;
		cout<<jian<<endl;
	}
	else if(jian>2)
	{
		for(int i=2;i<jian;i++)
	{
		if(jian%i==0)
		{
			judge=true;
			break;
		}
	} 
	if(judge)
	{
		cout<<"No Answer"<<endl;
		cout<<"0"<<endl;
	}
	else
	{
		cout<<"Lucky Word"<<endl;
		cout<<jian<<endl;
	}
	}
	else
	{
		cout<<"No Answer"<<endl;
		cout<<"0"<<endl;
	}
} 
