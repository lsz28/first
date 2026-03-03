#include <iostream>
using namespace std;

int main()
{
    //数组名用途
    //1、可以通过数组名统计整个数组占用内存大小
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    cout << "整个数组占用内存空间为：" << sizeof(arr) << endl;
    cout << "每个元素占用内存空间为：" << sizeof(arr[0]) << endl;
    cout << "数组中元素的个数为："     << sizeof(arr)/sizeof(arr[0]) << endl;

    //2、可以通过数组名查看数组首地址
    cout << "数组首地址为：" << arr << endl;
    cout << "数组中第一个元素地址为：" << (long long)&arr[0] << endl;  //long long使得将十六位地址通过int转换为10位地址，&表示取址符号，取一个元素的首地址
    cout << "数组中第二个元素地址为：" << (long long)&arr[1] << endl;  //第二个元素和第一个元素差四个字节

    //数组名是常量，值为数组首地址，不可以进行赋值操作
    //arr = 100;  不可以这样赋值修改


    return 0;

}
