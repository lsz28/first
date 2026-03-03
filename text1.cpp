#include <iostream>

using namespace std;


int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i>7&&i%7==0)
		{
			cout<<i<<endl;
		}
	
		string st=to_string(i);
	int s[st.size()];
	bool jud=false;
	for(size_t j=0;j<st.size();j++)
	{
	    s[j]=st[j]-'0';
		if(s[j]==7)
		{
			jud=true;
		}
	}	
	if(jud==true)
	{
		cout<<i<<endl;
	}
    }
	
	
	return 0;
};


