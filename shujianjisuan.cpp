#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int h1,h2,m1,m2,s1,s2;
	char ch;
	cin>>h1>>ch>>m1>>ch>>s1;
	cin>>h2>>ch>>m2>>ch>>s2;
	long time1=h1*3600+m1*60+s1;
	long time2=h2*3600+m2*60+s2;
	long time=time2-time1;
	long h=time/3600;
	long m=(time%3600)/60;
	long s=time%60;
	cout<<h<<":"
	<<setw(2)<<setfill('0')<<m<<":"
	<<setw(2)<<setfill('0')<<s<<endl;
return 0;
}
