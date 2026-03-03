#include <iostream>
using namespace std;

//程序员不释放就不释放 
int* func()  //返回的是一个地址 int*；形参的数据也会放在栈区
{
    //利用new关键字，可以将数据开辟到堆区
    //指针本质也是变量，这里的指针是局部变量，局部变量的数据放在栈上，即指针保存的数据是放在堆区
    int * p = new int(10);   //new关键字会返回一个地址，因此用栈上的指针来接收堆上数据的地址。
    return p;     //设置初始化值 
}
int main()
{
    //在堆区开辟数据
    int* p = func(); //堆区的地址返回给 *p 了，栈区数据是否，堆区数据没释放

    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;

    system("pause");

    return 0;

}
