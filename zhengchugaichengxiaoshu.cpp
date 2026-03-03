#include<iostream>
using namespace std;
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	double a=(double)y/x;//强制改小数 
	int e=n-a;//这里类型不一样,还是会出错 
	cout<<e<<endl;
	
return 0;
}
