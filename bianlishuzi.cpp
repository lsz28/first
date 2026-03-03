#include<iostream>
#include<bitset>
#include<string>
using namespace std;
int main()
{
	int x,y;
	cin>>x>>y;
	string twox=bitset<32>(x).to_string();
	int arrx[twox.size()];
	for(size_t i=0;i<twox.size();i++)
	{
		arrx[i]=twox[i]-'0';
	}
	string twoy=bitset<32>(y).to_string();
	int arry[twox.size()];
	for(size_t i=0;i<twoy.size();i++)
	{
		arry[i]=twoy[i]-'0';
	}
	int dis=0;
	for(int i=0;i<32;i++)
	{
		if(arrx[i]!=arry[i])
		{
			
			dis++;
		}
	}
	cout<<dis<<endl;
	
	
	
    
return 0;
}
