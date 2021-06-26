//
//  Form.cpp
//  OOP5_1
//
//  Created by Aaron on 2021/6/1.
//

#include <iostream>
#include <sstream>
#include "Form.h"
using std::cout;
using std::endl;

/* friend function */
std::ostream& operator<<(std::ostream &output, const Form &form){
    std::ostringstream s;
    s.precision(form.getPrecision());
    s.setf(form.getFmt(), std::ios_base::floatfield);
    s << form.getValue();
    return output << s.str();
}

