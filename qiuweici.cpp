#include<iostream>
using namespace std;
int main()
{
	//求个位
	int a;
	cin>>a;
	int o=a%10;
	int t=(a/10)%10;
	int th=(a/100)%10;
	cout<<o<<t<<th;
	
	 //求时间分成小时分钟秒 
	 int b;
	 cin>>b;
	 int h=b/3600;
	 int m=(b%3600)/60;
	 int s=b%60;
	 cout<<h<<endl;
	 cout<<m<<endl;
	 cout<<s<<endl;
return 0;
} 
