//
//  Complex.hpp
//  OOP3
//
//  Created by Aaron on 2021/4/27.
//

#ifndef Complex_hpp
#define Complex_hpp

#include <iostream>
using std::ostream;

class Complex{
    friend Complex Polar(const double leng, const double arg);
    friend double Norm(const Complex& x);
    friend double Abs(const Complex& x);
    friend double Arg(const Complex& x);
    friend Complex operator+(const Complex& x, const Complex& y);
    friend Complex operator-(const Complex& x, const Complex& y);
    friend Complex operator*(const Complex& x, const Complex& y);
    friend Complex operator/(const Complex& x, const Complex& y);
    friend Complex operator+=(Complex& x, const Complex& y);
    friend Complex operator-=(Complex& x, const Complex& y);
    friend Complex operator*=(Complex& x, const Complex& y);
    friend Complex operator/=(Complex& x, const Complex& y);
    friend bool operator==(const Complex& x, const Complex& y);
    friend bool operator!=(const Complex& x, const Complex& y);
    friend ostream& operator<<(ostream& o, const Complex& x);
    
public:
    Complex(const double re = 0, const double im = 0);
    Complex(const Complex& c);
    Complex& operator=(const Complex& c);
    
    Complex Polar(const double leng, const double arg);
    double Real();
    double Imag();
    double Norm();
    double Abs();
    double Arg();
    
    Complex operator++();
    Complex operator++(int);
    Complex operator--();
    Complex operator--(int);
    
    ~Complex();
        
private:
    double real;
    double imag;
};

Complex Polar(const double leng, const double arg);

#endif /* Complex_hpp */
