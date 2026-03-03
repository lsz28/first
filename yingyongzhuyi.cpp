#include <iostream>
using namespace std;

int main()
{
    //1、引用必须初始化
    int a = 10;
    int &b = a; // int &b; 是错误的，必须要初始化

    //2、引用在初始化后，不可以改变
    int c = 20;
    b = c;   // 赋值操作，而不是更改引用。把 c = 20 的数据20给了 b 指向的内存的数据，而 a、b 的指向的内存是一样的。
             // 这里并不是 b 指向 c 的内存。

    cout << "a = " << a << endl;  //a内存中数据变了,20
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    system("pause");

    return 0;

}
