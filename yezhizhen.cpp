#include <iostream>
using namespace std;

int main()
{
    //野指针
    int* p = (int*)0x1100; //随便指了一个内存,不合法
	                       // 0x1100是一个十六进制数，int*使得十六进制数强行转换为地址。
                           // 拿指针随便指向并没有申请这个内存的访问权限的内存。 

    cout << *p << endl; // 报错，地址并没有申请，你还要去访问它，就会报错
                        //dec是空白 

    system("pause");   

    return 0;

}
