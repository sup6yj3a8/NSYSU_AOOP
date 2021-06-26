//
//  lexer.cpp
//  OOP4
//
//  Created by Aaron on 2021/5/11.
//

#include "lexer.hpp"
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <exception>
#include <array>
#include <cctype>
#include <iomanip>
using std::cout;
using std::endl;

/* Instances */
static const Type INT("int", static_cast<int>(Tag::_BASIC), 4);
static const Type FLOAT("float", static_cast<int>(Tag::_BASIC), 8);
static const Type CHAR("char", static_cast<int>(Tag::_BASIC), 1);
static const Type BOOL("bool", static_cast<int>(Tag::_BASIC), 1);

static const Word AND("&&", static_cast<int>(Tag::_AND));
static const Word OR("||", static_cast<int>(Tag::_OR));
static const Word EQ("==", static_cast<int>(Tag::_EQ));
static const Word NE("!=", static_cast<int>(Tag::_NE));
static const Word LE("<=", static_cast<int>(Tag::_LE));
static const Word GE(">=", static_cast<int>(Tag::_GE));
static const Word MINUS("minus", static_cast<int>(Tag::_MINUS));
static const Word _TRUE("true", static_cast<int>(Tag::_TRUE));
static const Word _FALSE("flas", static_cast<int>(Tag::_FALSE));
static const Word TEMP("t", static_cast<int>(Tag::_TEMP));

static const Word IF("if", static_cast<int>(Tag::_IF));
static const Word ELSE("else", static_cast<int>(Tag::_ELSE));
static const Word WHILE("while", static_cast<int>(Tag::_WHILE));
static const Word DO("do", static_cast<int>(Tag::_DO));
static const Word BREAK("break", static_cast<int>(Tag::_BREAK));

/* Type class */

// Overloading operator ==
bool Type::operator==(const Type &p){
    return this->lexeme == p.lexeme && this->tag == p.tag && this->width == p.width;
}

// Check Type is char, int or float
bool Type::numeric(Type p){
    if ( p == CHAR || p == INT || p == FLOAT ) {
        return true;
    }else{
        return false;
    }
}

Type Type::max(Type p1, Type p2){
    if ( !numeric(p1) || !numeric(p2) ) {
        return Type(" ", 0, 0); // NULL
    }else if( p1 == FLOAT || p2 == FLOAT ){
        return FLOAT;
    }else if( p1 == INT || p2 == INT ){
        return INT;
    }else{
        return CHAR;
    }
}

/* Lexer Class */
Lexer::Lexer(const char fileName[])
:line(1), peek(' '), file(fileName, std::ios::in){
    reserve( IF );
    reserve( ELSE );
    reserve( WHILE );
    reserve( DO );
    reserve( BREAK );
    reserve( _TRUE );
    reserve( _FALSE );
    reserve( INT );
    reserve( FLOAT );
    reserve( CHAR );
    reserve( BOOL );
}

// Read a character from a file
void Lexer::readch(){
    char c;
    if ( file.get(c) ) {
        peek = c;
    }else{
        throw IOExeception("End of file reached");
    }
}

// Check if peek is c
bool Lexer::readch(const char &c){
    readch();
    if (peek != c) {return false;}
    peek = ' ';
    return true;
}

// Process token
Token Lexer::scan(){
    // Deal with meaningless characters
    for ( ; ; readch() ) {
        if (peek == ' ' || peek == '\t') {
            continue;
        }else if(peek == '\n'){
            ++line;
        }else{
            break;
        }
    }
    
    // If the next peek is end-of-file, the function is stopped.
    // Otherwise, print "Token: "
    if ( file.peek() == EOF ) {
        readch();
        return Token(' ');
    }else{
        cout << "Token: " << std::setw(10) << std::setiosflags(std::ios::left);
    }
    
    // Deal with specail characters
    static const std::array<std::string, 6> speChar = {"&&", "||", "==", "!=", "<=", ">="};
    static const std::array<Word, 6> speWord = {AND, OR, EQ, NE, LE, GE};
    
    for (int i=0; i<6; ++i) {
        if (peek == speChar[i][0]) {
            if ( readch(speChar[i][1]) ) {
                cout << speChar[i];
                return speWord[i];
            }else{
                cout << speChar[i][0];
                return Token(speChar[i][0]);
            }
        }
    }
    
    // Deal with digits
    if ( isdigit(peek) ) {
        // Deal with integer
        int v = 0;
        do{
            v = 10 * v + peek - '0' ;
            readch();
        }while ( isdigit(peek) );
        if (peek != '.') {
            cout << v;
            return  Num(v);
        }
        
        // Deal with float
        float x = v;
        float d = 10;
        for ( ; ; readch() ) {
            if ( !isdigit(peek) ) {break;}
            x += (peek - '0') / d;
            d *= 10;
        }
        cout << x;
        return Real(x);
    }
    
    // Deal with letters
    if ( isalpha(peek) ) {
        std::string buffer;
        do{
            buffer += peek;
            readch();
        }while( isalpha(peek) );
        
        if ( words.find(buffer) != words.end() ) {
            cout << words.find(buffer)->second.lexeme;
            return words.find(buffer)->second;
        }
        
        Word w( buffer, static_cast<int>(Tag::_ID) );
        reserve(w);
        cout << buffer;
        return std::move(w);
    }
    
    // Deal with others
    Token tok(peek);
    cout << peek;
    peek = ' ';
    return tok;
}
