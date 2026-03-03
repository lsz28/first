//字符型
//作用：指代字符,内存小,但后面的字母只能为一个字母
//语法：char aaa='a'(单引号)

#include<iostream>
using namespace std;
int main()

{
	char ac='b';
	cout<<"c"<<endl;//用了双引号是直接打出来的意思
	cout<<ac<<endl;//没用双引号是变量
	
	//char还可以用来读取符号 
	char ch;
	int a,b;
	cin>>ch>>a>>ch>>b>>ch;//ch可以指代输入的()和, 
	cout<<"("<<a<<","<<b<<")"<<endl;
	
	//字母型的ASCLL值（就是网上看到过的底层代码逻辑，用数字代替字符）
	cout<<(int)ac<<endl;//int即整型
	cout<<(int)'b'<<endl;//都ok啦
	
	//\n，起换行作用
	cout<<"hello world\n";//c语言里面的，与<<endl作用一样
	
	//用'\\ '打出一个'\'
	cout<<"\\"<<endl;

	//\t使自动对齐
	cout<<"aa\thello"<<endl;
	cout<<"aaa\thello"<<endl;
	
	return 0;
}
	
/*转义字符
作用：用一些符号表示出特殊作用和含义
有三个要记的
\n 换行符 
\\  表示一个'\'
\t  水平制表符 自动补充八个，使整齐*/
