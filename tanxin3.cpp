#include<bits/stdc++.h>
using namespace std;
struct Match
{
	int start;
	int end;
};
bool com(Match a,Match b) 
{
	return a.end<b.end;
}
int main()
{
	int n;
	cin>>n;
	vector<Match>match(n); 
	for(int i=0;i<n;i++)
	{
		cin>>match[i].start>>match[i].end;
	}
	sort(match.begin(),match.end(),com);
	int sum=1;
	int first=match[0].end;
	for(int i=1;i<n;i++)
	{
		if(match[i].start>=first)
		{
			sum+=1;
			first=match[i].end;
		}
	}
	cout<<sum<<endl;
	
	
return 0;
}
