#include <iostream>
using namespace std;

void swap(int* p1, int* p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    //指针和函数
    int a = 10;
    int b = 20;

    swap(&a, &b);//即完整的*p赋值为了&a 

    //如果是地址传递，可以修改实参，原来 a = 10；b = 20，地址传递后 a = 20，b = 10.
    cout << "a =" << a << endl;
    cout << "b =" << b << endl;
    //如果是值传递，不可以修改实参，原来 a = 10；b = 20，值传递后 a = 10，b = 20.

    system("pause");

    return 0;

}
