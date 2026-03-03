#include <iostream>
using namespace std;

//值传递
//定义函数，实现两个数字进行交换函数

//如果函数不需要返回值，声明的时候可以写void
void swap(int num1, int num2)
{
    cout << "交换前：" << endl;
    cout << "num1= " << num1 << endl;
    cout << "num2= " << num2 << endl;

    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "交换后：" << endl;
    cout << "num1= " << num1 << endl;
    cout << "num2= " << num2 << endl;

    return;  //前面写了void，所以不需要返回值。返回值不需要的时候，也可以不写return。
}


int main()
{
    //main函数中调用add函数
    int a = 10;
    int b = 20;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    //当我们把值传递的时候，函数的形参发生发生改变，并不会影响实参
    swap(a, b);//一个函数,已经包含了输出语句,与下面的无关 
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    system("pause");   //按任意键继续

    return 0;

}
