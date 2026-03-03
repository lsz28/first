//三目运算符
//形式:表达式1?表达式2:表达式3
//如果满足表达式1则输出表达式2,否则输出表达式3 

#include <iostream>
using namespace std;
int main()
{ int a=1,b=2;

cout<<(a>b?a:b)<<endl;

//三目运算符也可以赋值
(a>b?a:b) =100;
cout<<a<<endl;
cout<<b<<endl;
 








return 1;
} 
