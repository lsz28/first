#include<bits/stdc++.h>
using namespace std;
int main()
{
	string zhao;
	cin>>zhao;
	cin.ignore();
    string wen;
	getline(cin,wen);
	int i=0;
	int sum=0; 
	vector<int>shi;
	for(int i=0;i<zhao.size();i++)
	{
		if(zhao[i]>'A'&&zhao[i]<='Z')
		zhao[i]+=32;
	}
	for(int i=0;i<wen.size();i++)
	{
		if(wen[i]>'A'&&wen[i]<='Z')
		wen[i]+=32;
	}
	for(int j=0;j<wen.size();j++)
	{
//		for(int j=0;j<zhao.size();j++)
//		{
//			if
//		}
        if(j==0||(j>0&&wen[j-1]==' ')||zhao[i-1]==wen[j-1])
        {
		
        if(zhao[i]==wen[j])
        {
        	shi.push_back(j);
        	if(i==zhao.size()-1)
        	{
        		sum+=1;
        		i=0;
        		continue;
			}
			else
			{
				if(zhao[i+1]==wen[j+1])
				{
					i++;
					
				continue;
				}
			}
		}
		else
		{
			continue;
		}
	    }
	}
	if(sum>0)
	{
		cout<<sum<<" "<<shi[0];
	}
	else
	{
		cout<<"-1"<<endl;
	}
}    
