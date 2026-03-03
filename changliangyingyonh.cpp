#include <iostream>
using namespace std;

void showValue(const int& val)//常量指针,使无法再修改值,防止后面把默认值改了 
{
    // val = 1000; 报错，不能修改了
    cout << "val = " << val << endl;
}

int main()
{
    //常量引用
    //使用场景：用来修饰形参，防止误操作

    /*
    int a = 10;
    int& ref = 10;  //报错，引用必须引一块合法的内存空间
    */

    //加上const之后，编译器代码修改为 int temp = 10; const in & ref = temp 
    const int& ref = 10;
    //ref = 20;  //加入const之后变为只读，不可以修改

    int a = 100;
    showValue(a);//函数代入的时候既代入为别名,也代入为常量指针 
    cout << "a = " << a << endl;
    
    a=200;
    showValue(a);//但是a可以改啊 
    cout << "a = " << a << endl;
    system("pause");
    
    return 0;

}
