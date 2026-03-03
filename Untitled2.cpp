#include<bits/stdc++.h>
using namespace std;
int main()
{
	int temp=345;
	vector<int>weishu;
while(temp%10>0)
{
	weishu.push_back(temp%10);
	temp=temp/10;
} 
reverse(weishu.begin(),weishu.end());
for(int i=0;i<weishu.size();i++)
{
	cout<<weishu[i];
}
} 
