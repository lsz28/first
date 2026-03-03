#include<iostream>
using namespace std;
int main()
{
	int arr[3]={1,8,5};
	int max=0;
	for(int i=0;i<3;i++)
	{
		if(arr[i]>arr[max])
		max=i;
	}
	cout<<arr[max];
return 0;
}
