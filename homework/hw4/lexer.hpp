//
//  lexer.hpp
//  OOP4
//
//  Created by Aaron on 2021/5/11.
//

#ifndef lexer_hpp
#define lexer_hpp

#include <map>
#include <string>
#include <fstream>

enum class Tag: int{
    _AND    = 256,
    _BASIC  ,
    _BREAK  ,
    _DO     ,
    _ELSE   ,
    _EQ     ,
    _FALSE  ,
    _GE     ,
    _ID     ,
    _IF     ,
    _INDEX  ,
    _LE     ,
    _MINUS  ,
    _NE     ,
    _NUM    ,
    _OR     ,
    _REAL   ,
    _TEMP   ,
    _TRUE   ,
    _WHILE  ,
};

class Token{
public:
    Token(const int &t):tag(t){}
    
    // Get tag
    inline char toString(){return static_cast<char>(tag);}
    
    int tag;
};

class Word : public Token{
public:
    Word(const std::string &s,const int &t):Token(t), lexeme(s){}
    
    // Get lexeme
    inline std::string toString(){return lexeme;}
    
    std::string lexeme;
};

class Type : public Word{
public:
    Type(const std::string &s,const int &tag,const int &w = 0):Word(s, tag), width(w){};
    bool operator==(const Type &p);
    static bool numeric(Type p);
    static Type  max(Type p1, Type p2);
    
    int width;
};

class Num : public Token{
public:
    Num(const int &v):Token( static_cast<int>(Tag::_NUM) ), value(v){};
    
    // Get value
    inline int toString(){return value;}
    
    const int value;
};

class Real : public Token{
public:
    Real(const float &v):Token( static_cast<int>(Tag::_REAL) ) ,value(v){};
    
    // Get value
    inline float toString(){return value;}
    
    const float value;
};

class Lexer{
public:
    explicit Lexer(const char fileName[]);
    
    // Insert key-value into words.
    inline void reserve(const Word &w){words.insert(std::pair<std::string, Word>(w.lexeme, w));}
    
    void readch();
    bool readch(const char &c);
    Token scan();
    
    int line;
    
private:
    char peek;
    std::map<std::string, Word> words;
    std::ifstream file;
};

class IOExeception : public std::exception{
public:
    explicit IOExeception( const std::string &m):message(m){}
    const char* what() const noexcept override{ return message.c_str(); }
    
private:
    std::string message;
};

#endif /* lexer_hpp */
