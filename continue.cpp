//continue
//会停止下面的代码运行,重新循环 

#include<iostream>
using namespace std;
int main()
{
//	for(int i=1;i%2!=0&&i<10;i++)[会直接在2执行时就终止了]
//	{
//		cout<<i<<endl;
//	}

    for(int i=0;i<10;i++)
    {
    	if(i%2==0)
    {
		continue;
    }
    cout<<i;
	}
	
return 0;
}
