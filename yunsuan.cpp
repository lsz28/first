#include<bits/stdc++.h>
using namespace std;
string jias(int s1,int s2)
{
	return to_string(s1)+"+"+to_string(s2)+"="+to_string(s1+s2);
};
string jians(int s1,int s2)
{
	return to_string(s1)+"-"+to_string(s2)+"="+to_string(s1-s2);
};
string chengs(int s1,int s2)
{
	return to_string(s1)+"*"+to_string(s2)+"="+to_string(s1*s2);
};
int main()
{
	int num;
	cin>>num;
	string s;
	char ch;
	int shu;
	vector<int>jia;	
	vector<int>jian;
	vector<int>cheng;
		s.push_back(ch);
		if(ch=='a')
		{
		
		while(cin>>shu)
		{
			jia.push_back(shu);
		}
		}
		else if(ch=='b')
		{
			
			while(cin>>shu)
			{
				jian.push_back(shu);
			}
		}
		else if(ch=='c')
		{
			
			while(cin>>shu)
			{
				cheng.push_back(shu);
			}
		}
	for(int i=0;i<s.size();i++) 
	{
		if(s[i]=='a')
		{
			for(int j=0;j<jia.size()-1;j++)
			{
//				string sum=jias(jia[j],jia[j+1]);
//				cout<<jia[j]"+"jia[j+1]"="sum<<endl;
				string sjia=jias(jia[j],jia[j+1]);
				j+=2;
				cout<<sjia<<endl;
				cout<<sjia.size()<<endl; 
			}
		}
		else if(s[i]=='b')
		{
			for(int j=0;j<jian.size()-1;j++)
			{
				string sjian=jians(jian[j],jian[j+1]);
				j+=2;
				cout<<sjian<<endl;
				cout<<sjian.size()<<endl; 
			}
		}
		else if(s[i]=='c')
		{
			for(int j=0;j<cheng.size()-1;j++)
			{
				string scheng=chengs(cheng[j],cheng[j+1]);
				j+=2;
				cout<<scheng<<endl;
				cout<<scheng.size()<<endl; 
			}
		}
		
	}
}
