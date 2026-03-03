#include <iostream>
using namespace std;

//1、值传递
void mySwap01(int a,int b)
{
    int temp = a;
    a = b;
    b = temp;
}

//2、地址传递
void mySwap02(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//2、引用传递
//这里面的&a的实参为a(恰巧为a，恰巧一样)的别名，对&a中的a操作修改，就是对实参a修改
void mySwap03(int &a, int &b)  //参数这里指的是把a的别名赋值,会修改是因为括号里面的副本改了,原名也会改 
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10;
    int b = 20;

    mySwap01(a, b);  //值传递，形参不会修饰实参
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    mySwap02(&a, &b); //地址传递，形参会修饰实参

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    mySwap03(a, b); //引用传递，形参会修饰实参

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    system("pause");

    return 0;

}
