//
//  Complex.cpp
//  OOP3
//
//  Created by Aaron on 2021/4/27.
//

#include <cmath>
#include "Complex.hpp"

/*  friend function */

// Poar form
Complex Polar(const double leng, const double arg){
    Complex c;
    return c.Polar(leng, arg) ;
}

// Get norm value
double Norm(const Complex& x){return  x.real*x.real + x.imag*x.imag;}

// Get absolute value
double Abs(const Complex& x){return sqrt( Norm(x) );}

// Get angle
double Arg(const Complex& x){return atan2(x.imag, x.real);}

// Overloading +
Complex operator+(const Complex& x, const Complex& y){
    Complex c;
    c.real = x.real + y.real;
    c.imag = x.imag + y.imag;
    return c;
}

// Overloading -
Complex operator-(const Complex& x, const Complex& y){
    Complex c;
    c.real = x.real - y.real;
    c.imag = x.imag - y.imag;
    return c;
}

// Overloading *
Complex operator*(const Complex& x, const Complex& y){
    Complex c;
    c.real = x.real * y.real - x.imag * y.imag;
    c.imag = x.real * y.imag + x.imag * y.real;
    return c;
}

// Overloading /
Complex operator/(const Complex& x, const Complex& y){
    Complex c;
    c.real = ( x.real * y.real + x.imag * y.imag ) / ( y.real * y.real + y.imag * y.imag );
    c.imag = ( - x.real * y.imag + x.imag * y.real ) / ( y.real * y.real + y.imag * y.imag );
    return c;
}

// Overloading +=
Complex operator+=(Complex& x, const Complex& y){
    x = x + y;
    return x;
}

// Overloading -=
Complex operator-=(Complex& x, const Complex& y){
    x = x - y;
    return x;
}

// Overloading *=
Complex operator*=(Complex& x, const Complex& y){
    x = x * y;
    return x;
}

// Overloading /=
Complex operator/=(Complex& x, const Complex& y){
    x = x / y;
    return x;
}

// Overloading ==
bool operator==(const Complex& x, const Complex& y){
    return x.real == y.real && x.imag == y.imag;
}

// Overloading !=
bool operator!=(const Complex& x, const Complex& y){
    return !( x.real == y.real && x.imag == y.imag );
}

// Overloding <<
ostream& operator<<(ostream& o, const Complex& x){
    o << '(' << x.real << ',' << x.imag << ')';
    return o;
}

/* Complex */

// Default constructor
Complex::Complex(const double re , const double im)
:real(re), imag(im)
{}

// Copy constructor
Complex::Complex(const Complex& c)
:real(c.real), imag(c.imag)
{}

// Copy assignment operator
Complex& Complex::operator=(const Complex& c){
    if(&c!=this){ // Avoid self-assignment
        this->real = c.real;
        this->imag = c.imag;
    }
    return *this;
}

// Polar form
Complex Complex::Polar(const double leng, const double arg){
    this->real = leng * cos(arg);
    this->imag = leng * sin(arg);
    return *this;
}

// Get real
double Complex::Real(){return real;}

// Get imag
double Complex::Imag(){return imag;}

// Get norm value
double Complex::Norm(){return Real()*Real() + Imag()*Imag();}

// Get absolute value
double Complex::Abs(){return sqrt( Norm() );}

// Get angle
double Complex::Arg(){return atan2( Imag(), Real() );};

// Prefix increment
Complex Complex::operator++(){
    ++real;
    ++imag;
    return *this;
}

// Postfix increment
Complex Complex::operator++(int){
    Complex copy = *this;
    ++real;
    ++imag;
    return copy;
}

// Prefix decreasement
Complex Complex::operator--(){
    --real;
    --imag;
    return *this;
}

// Postfix decreasement
Complex Complex::operator--(int){
    Complex copy = *this;
    --real;
    --imag;
    return copy;
}

// Destructor
Complex::~Complex(){}
