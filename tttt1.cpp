#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int d;
    cin>>d;
    int sum=0;
    int day=0;
    int c=1; 
    while(1)//总天循环 
    {
    	for(int i=0;i<c;i++)//重复的c ,重复的钱 
    	{
    		day++;
    		if(day>d)
    		break;
    		else
    		{
    			sum+=c;
    			
			} 
    		
		}
		c++; 
		if(day>d)
    		break;
	}
	cout<<sum<<endl;
}

