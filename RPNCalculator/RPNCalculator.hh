// Class declaration file for RPNCalculator

#ifndef RPN_CALCULATOR_HH
#define RPN_CALCULATOR_HH

#include <iostream>
#include <string>
#include <list>
#include <cmath>

class RPNCalculator
{
    std::list<int> stack;
public:
    RPNCalculator() {} // basic constructor
    void error();
    void add();
    void subtract();
    void multiply();
    void divide();
    void swap();
    void dupe();
    void calculate();
    bool checkSymbol(std::string);
    void checkInteger(std::string);
    void run();
};

#endif
