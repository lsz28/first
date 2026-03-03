#include <iostream>
using namespace std;

// 定义复数类
class Complex {
private:
    double real;  // 实部
    double imag;  // 虚部
public:
    // 构造函数，带默认参数
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    // 获取实部和虚部的只读函数
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // 重载加法运算符
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // 重载减法运算符
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // 重载乘法运算符（按题目给定规则）
    Complex operator*(const Complex& other) const {
        double newReal = real * other.real - imag * other.imag;
        double newImag = real * other.imag + imag * other.real;
        return Complex(newReal, newImag);
    }

    // 友元函数：重载输入运算符
    friend istream& operator>>(istream& in, Complex& c) {
        in >> c.real >> c.imag;
        return in;
    }

    // 友元函数：重载输出运算符（按指定格式）
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1, c2, c3;  // 定义三个复数对象
    
    // 输入两个复数
    cin >> c1;
    cin >> c2;

    // 加法运算并输出
    c3 = c1 + c2;
    cout << "Sum: " << c3 << endl;

    // 减法运算并输出
    c3 = c1 - c2;
    cout << "Difference: " << c3 << endl;

    // 乘法运算并输出
    c3 = c1 * c2;
    cout << "Product: " << c3 << endl;

    return 0;  // turn 0; 程序正常结束
}
