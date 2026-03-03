//数据类型输出
#include<iostream> 
#include<string>
#include<iomanip>//精度头文件 
using namespace std;
int main()
{
	//整型输出
	int    a=0;
	cout<<   "请输出a的赋值"   <<endl;
	cin>>a;//int是可以修改值，但不能重新定义 
	cout<<"整型a为"<<a<<endl;
	
	//设置输出精度
	int a1 =1;
	double b1=a+1;
	double b2=a1+2; 
	cout<<setw(5)<<setfill('0')<<b2<<endl;//设置宽度并且向右对齐,setfill是在前面补东西 
//	cout<<fixed<<setprecision(5)<<b1<<endl;//修改精度的操作,是持久化的,会影响下面的所有浮点型 (小数部分保留几位)
	cout<<setprecision(5)<<b1<<endl;//保留有效数字几位,四舍五入 
	//cout<<setw(5)<<b1<<endl;这样不太行,上面的小数设置会影响下面的输出并且超过了下面的宽度,导致,setw失效 
	
	//字符型输出
	char aaa='a';
	cout<<"请输出aaa的赋值"<<endl;
	cin>>aaa;
	cout<<"字符aaa为"<<aaa<<endl; 
	 
	
	//字符串型输出
	string b="aaa";
	cout<<"请输出b的赋值"<<endl;
	cin>>b;
	cout<<"字符串型为"<<b<<endl; 
	
	//bool输出
	bool flag=false;
	cout<<"请输出flag的赋值"<<endl;
	cin>>flag;//bool只要是非0都是true 
	cout<<"flag为"<<flag<<endl; 
	
	return 0;
}
