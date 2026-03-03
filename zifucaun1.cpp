#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cin.ignore(); 
	string s;
	getline(cin,s) ;
//    vector<string>str;
//    string s;
//	while(cin>>s)
//	{
//		str.push_back(s);
//	}
	for(int i=0;i<s.size();i++)
	{
		cout<<char((s[i]-'a'+n)%26+'a');
	}
	return 0;
}
