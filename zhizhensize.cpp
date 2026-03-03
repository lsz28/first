#include <iostream>
using namespace std;

int main()
{
    //指针所占内存空间
    int a = 10;

    /*
    int * p; //p变量是 int * 数据类
    p = &a;

    等价于：
    int * p = &a;
    */

    int * p = &a; 



//在64位操作系统下，不管什么类型的指针都占8个字节的内存，但是实际开发环境一般都是32位操作系统下。
//在32位操作系统下，不管什么类型的指针都占4个字节的内存。
    cout << "sizeof(int * )= " << sizeof(p) << endl;
    cout << "sizeof(int * )= " << sizeof(int*) << endl; 
    cout << "sizeof(float * )= " << sizeof(float*) << endl;
    cout << "sizeof(double * )= " << sizeof(double*) << endl;
    cout << "sizeof(char * )= " << sizeof(char*) << endl;

    system("pause");   //按任意键继续

    return 0;

}
