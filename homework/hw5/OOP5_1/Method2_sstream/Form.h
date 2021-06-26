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
    :pre(p), value(0), fmt(0)
    {}
    
    // Overloading copy operator (=)
    inline Form& operator=(const Form &B){
        if (this != &B) { // Avoid self-copy
            this->pre = B.getPrecision();
            this->value = B.getValue();
            this->fmt = B.getFmt();
        }
        return *this;
    }
    
    // Overloading () to set the value
    inline Form& operator()(const double n) {
        value = n;
        return *this;
    }
    
    // Set the precision
    inline Form& precision(const unsigned int& p){
        pre = p;
        return *this;
    }
    
    // Use scientific format
    inline Form& scientific(){
        fmt = std::ios_base::scientific;
        return *this;
    }
    
    // Use fixed format
    inline Form& fixed(){
        fmt = std::ios_base::fixed;
        return *this;
    }
    
    inline unsigned int getPrecision() const {return pre;}
    inline double getValue() const {return value;}
    inline int getFmt() const {return fmt;}
    
private:
    unsigned int pre; // precision
    double value;
    int fmt; // Format: general, scientific, fixed
};

#endif /* Form_h */
