//
//  Vector.h
//  OOP5_2
//
//  Created by Aaron on 2021/6/1.
//

#ifndef Vector_h
#define Vector_h
#define __TRACE__

#include <vector>
#include <iostream>
#include "Trace.h"

// General (T) vector class
template<class T>
class vector{
public:
    // Default constructor
    explicit vector(const int& size = 0)
    :vec(size){
        Trace dummy("vector<T>::vector(int)");
        std::cout << "   count = 1" << std::endl;
    }
    
    // Destructor
    ~vector(){
        Trace dummy("vector<T>::~vector(int)");
        std::cout << "   count = 1" << std::endl;
    }
    
    // Overloading []
    inline T& operator[](const unsigned int& i){return vec[i];}
    
    // Get the lvalue of an i-th element
    inline T& elem(const unsigned int& i){return vec[i];}
    
private:
    std::vector<T> vec;
};

// Specialized (void*) vector class
template<>
class vector<void*>{
public:
    // Default constructor
    explicit vector(const int& size = 0)
    :vec(size){
        Trace dummy("vector<void*>::vector(int)");
        std::cout << "   count = " << ++count << std::endl;
    }
    
    // Destructor
    ~vector(){
        Trace dummy("vector<T>::~vector(int)");
        std::cout << "   count = " << count-- << std::endl;
    }
    
    // Overloading []
    inline void*& operator[](const unsigned int& i){return vec[i];}
    
    // Get the lvalue of an i-th element
    inline void*& elem(const unsigned int& i){return vec[i];}

private:
    std::vector<void*> vec;
    static int count;
};

// Specialized (T*) vector class
template<typename T>
class vector<T*> : private vector<void*>{
public:
    typedef vector<void*> base;
    
    // Default constructor
    explicit vector(const int& size = 0)
    :base(size), vec(size){
        Trace dummy("vector<T*>::vector(int)");
    }
    
    // Destructor
    ~vector(){
        Trace dummy("vector<T*>::~vector(int)");
    }
    
    // Overloading []
    inline T*& operator[](unsigned int i){return vec[i];}
    
    // Get the lvalue of an i-th element
    inline T*& elem(unsigned int i){return vec[i];}
    
private:
    std::vector<T*> vec;
};

#endif /* Vector_h */
