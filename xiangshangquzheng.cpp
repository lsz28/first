#include<iostream>
using namespace std;
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	int a=(y+x-1)/x; //向上取整 
	int e=n-a;
	cout<<e<<endl;
	
return 0;
}
