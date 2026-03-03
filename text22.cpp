#include<iostream>
using namespace std;
int main()
{
	int q,b;
	double a;
	cin>>q>>b;
	if(q<=5000)
	{
		a=0;
		cout<<a<<endl;
	}
	if(q>5000)
	{
	
	int c=q-5000-b;
	if(c<=3000)
	{
		a=c*0.03;
		cout<<a<<endl;
	}
	else if(c>=3000.01&&c<=12000)
	{
		a=c*0.1-210;
		cout<<a<<endl;
	}
	else if(c>=12000.01&&c<=25000)
	{
		a=c*0.2-1410;
		cout<<a<<endl;
	}
	else if(c>=25000.01&&c<=35000)
	{
		a=c*0.25-2660;
		cout<<a<<endl;
	}
	else if(c>=35000.01&&c<=55000)
	{
		a=c*0.30-4410;
		cout<<a<<endl;
	}
	else if(c>=55000.01&&c<=80000)
	{
		a=c*0.35-7160;
		cout<<a<<endl;
	}
	else if(c>=80000.01)
	{
		a=c*0.45-15160;
		cout<<a<<endl;
	}
}
return 0;
}



