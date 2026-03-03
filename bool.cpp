//bool 类型
//就是真和假的判断，本质是1或0
#include <iostream>
using namespace std;
int main()
{
	bool voi=true;
	cout<<voi<<endl;//输出来是1
	
	voi=false;//不用再次打bool
	cout<<voi<<endl;//输出来是0
	
	//还可以作条件判断
	int year;
	cin>>year;
	bool a=year%100==0;
	if(a)
	{
		cout<<"right"<<endl;
	}
	else
	{
		cout<<"wrong"<<endl;
	}
	cout<<"bool所占内存空间"<<sizeof(bool)<<endl;
	return 0;
}
