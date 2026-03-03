//class Base {
//public:
//    ~Base() {
//        std::cout << "Base destructor called" << std::endl;
//    }
//};
// 
//class Derived : public Base {
//public:
//    ~Derived() {
//        std::cout << "Derived destructor called" << std::endl;
//    }
//};
// 
//int main() {
//    Base* obj = new Derived();  // 基类指针指向派生类对象
//    delete obj;  // 销毁对象
//    return 0;
//}




//虚析构函数 
//语法:virtual ~xxxx()   (xxx与类名一样) 
class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor called" << std::endl;
    }
};
 
class Derived : public Base {
public:
    ~Derived() //无参无返 
	{
        std::cout << "Derived destructor called" << std::endl;
    }
};
 
int main() {
    Base* obj = new Derived();  // 基类指针指向派生类对象
    delete obj;  // 销毁对象,销毁的同时还是会运行,会先用析构函数 
    return 0;
}

//1.首先,析构函数是为了用和删的时候防止把基类删了

//2.析构函数用虚函数是为了可以同时调用基类和析构类 

//3.输出的时候是先基类的构造函数,派生类的构造函数,派生类的析构函数,基类的析构函数 
