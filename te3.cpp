#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	vector<string>z;
	vector<char>c;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='a')
		{
			c.push_back(s[i]);
			while(s[i+1]==s[i]+1)
			{
				c.push_back(s[i+1]);
				i++;
			}
			c.push_back('\0');
			for(int j=0;j<c.size()-1;j++)
			{
				z[i].push_back(c[j]);
			}
		}
	}
//	int max=s[0].size;
	for(int i=0;i<z.size();i++)
	{
		if(z[i].size()>z[i+1].size())
		{
			string temp=z[i];
			z[i]=z[i+1];
			z[i+1]=temp;
		}
	}
	cout<<z[z.size()-1]<<endl;
	
}
