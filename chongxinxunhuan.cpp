#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int liv[n+1];
	for(int i=1;i<=n;i++)
	{
		liv[i]=1;//掌握一个出列的技巧 
	}
	int cou=0;
	int i=1;
	int out=0; 
	while(out<n)//掌握最终循环的技巧 
	{
		if(liv[i]==1)//掌握跳数的技巧 
		{
			cou++;
		}
		if(cou==m)
		{
			cout<<i<<" ";
			liv[i]=0;//数到三出列 
			cou=0; 
			out++;
		}
		i++;//
		if(i>n)
		{
			i=1;//掌握从头重新循环的技巧 
		}
	}
	
	
	
	
return 0;
} 
