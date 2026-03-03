#include<iostream>
using namespace std;
int main()
{
	int arr[9]={4,2,8,0,5,7,1,3,9};	
    for(int i=0;i<9;i++)
	{
		int max=i;
		for(int j=i+1;j<9;j++)
		{
			if(arr[j]<arr[max])
			{
				int temp=arr[j];
				arr[j]=arr[max];
				arr[max]=temp;
			}
		}
	}
	for(int i=0;i<9;i++)
	{
		cout<<arr[i]<<endl;
	}
	
return 0;
}
