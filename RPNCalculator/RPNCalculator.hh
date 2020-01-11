// Class declaration file for RPNCalculator

#ifndef RPN_CALCULATOR_HH
#define RPN_CALCULATOR_HH

#include <iostream>
#include <string>
#include <list>
#include <cmath>

class RPNCalculator
{
    std::list<int> stack; // List that holds all the integers
public:
    RPNCalculator() {} // basic constructor
    void error(); // Prints out error messages
    void add(); // Adds the top two numbers of stack
    void subtract(); // Subtracts the top two numbers of stack
    void multiply(); // multiplies the top two numbers of stack
    void divide(); // divides the top two numbers of stack
    void swap(); // swaps the top two numbers of stack
    void dupe(); // duplicates the top numbers of stack
    void calculate(); // outputs the last number of stack
    bool checkSymbol(std::string); // checks to see if the input is an operator
    void checkInteger(std::string); // checks to see if the input is an integer
    void run(); // gathers the input.
};

#endif
