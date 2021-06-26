//
//  Form.cpp
//  OOP5_1
//
//  Created by Aaron on 2021/6/1.
//

#include <iostream>
#include "Form.h"
using std::cout;
using std::endl;

/* friend function */
std::ostream& operator<<(std::ostream &output, const Form &form){
    std::ios_base::fmtflags oriForm = output.flags();
    switch (form.type) {
        case 0:
            output << std::setprecision(form.getPrecision()) << form.getNumber();
            break;
            
        case 1:
            output << std::scientific << std::setprecision(form.getPrecision())  << form.getNumber();
            break;
            
        case 2:
            output << std::fixed << std::setprecision(form.getPrecision()) << form.getNumber();
            break;
            
        default:
            break;
    }
    
    output.flags(oriForm);
    output << std::setprecision(6);
    return output;
}
