#include <iostream>
using namespace std;

int main()
{
    
    int a = 10;
    int b = 10;

    //1、const修饰指针 常量指针(就近原则,离一整个数近,就不能改数,离指针近,就不能改指针所对应的对象) 
    const int* p = &a;  // const(常量) *(指针) → 常量指针 
    // *p = 20;  错误，常量指针 → 指针指向的值不可以改，指针的指向可以改
    p = &b; // 正确

    //2、const修饰指针 指针常量
    int* const p2 = &a; // *(指针)const(常量) → 指针常量
    *p2 = 100; //正确的
    p2 = &b;  //错误，指针的指向不可以改，指针指向的 值可以改

    //3、const修饰指针和常量
    const int* const p3 = &a;
    *p3 = 100;  //错误
    p3 = &b;  //错误

    system("pause");   

    return 0;

}
