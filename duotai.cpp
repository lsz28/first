class Animal {
public:
    virtual void sound() {  // 虚函数
        std::cout << "Animal makes a sound\n";
    }
};
 
class Dog : public Animal {
public:
    void sound() override {  // 重写基类的虚函数,override 
        std::cout << "Dog barks\n";
    }
};
 
class Cat : public Animal {
public:
    void sound() override {
        std::cout << "Cat meows\n";
    }
};
 
int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();
    
 //  指针输出 
    animal1->sound();  // 输出：Dog barks
    animal2->sound();  // 输出：Cat meows
 
    delete animal1;
    delete animal2;
    return 0;
}

//1.继承
//2.虚函数
//3.指针 
