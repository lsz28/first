class Animal {
public:
    void eat() {
        std::cout << "Eating...\n";
    }
};
 //         继承的语法 
class Dog : public Animal {  // Dog 类继承自 Animal 类
public:
    void bark() {
        std::cout << "Barking...\n";
    }
};


//在这个例子中，Dog 类继承了 Animal 类的 eat 方法，并新增了 bark 方法。Dog 对象可以调用 eat，因为它从 Animal 类继承了这一功能。
//继承就是子代不用再写一遍上面有的函数,就可以自带这个函数,而且还可以再扩展 
