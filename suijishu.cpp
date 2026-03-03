#include<iostream>
using namespace std;
#include<ctime>
#include<stdlib.h>
int main()
 
{
	srand((unsigned int )time(NULL));
	int num=rand()%100+1;//rand()%100是指0-99,加了一是1-100
	while(1)
	{
	
	int a;
	cin>>a;
	if(a>num)
	{
		cout<<"bigger"<<endl;
	} 
	else if(a<num)
	{
		cout<<"smaller"<<endl;
	
	}
	else
	{
		cout<<"congratulation"<<endl;
		break;
	}
	
	} 

return 1;
}
