#include <iostream>
using namespace std;

//函数的声明
//比较函数，实现两个整型数字进行比较，返回较大的值。

//提前告诉编译器函数的存在，可以利用函数的声明
//函数的声明
//声明可以写多次，但是定义只能有一次
void max(int a, int b);


int main()
{
    int a = 10;
    int b = 20;
    max(a, b);

    system("pause");   //按任意键继续

    return 0;

}

//函数定义在main函数之后，必须要在main函数之前写函数的声明
void max(int a, int b)
{
    cout<<(a > b ? a : b)<<endl;
}
