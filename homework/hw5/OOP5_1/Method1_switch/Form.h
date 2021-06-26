//
//  Form.h
//  OOP5_1
//
//  Created by Aaron on 2021/6/1.
//

#ifndef Form_h
#define Form_h

#include <iostream>
#include <ostream>
#include <iomanip>

class Form{
    friend std::ostream& operator<<(std::ostream &output, const Form &form);
public:
    explicit Form(const unsigned int& p = 6)
    :pre(p), number(0), type(0)
    {}
    
    Form& operator=(const Form &B){
        this->pre = B.getPrecision();
        return *this;
    }
    
    inline Form& operator()(const double n) {
        number = n;
        return *this;
    }
    
    inline Form& precision(const unsigned int& p){
        pre = p;
        return *this;
    }
    
    inline Form& scientific(){
        type = 1;
        return *this;
    }
    
    inline Form& fixed(){
        type = 2;
        return *this;
    }
    
    inline unsigned int getPrecision() const {return pre;}
    inline double getNumber() const{return  number;}
    
private:
    double number;
    unsigned int pre;
    int type;
};

#endif /* Form_h */
