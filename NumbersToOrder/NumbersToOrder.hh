// Class declaration file for NumbersToOrder

#ifndef NUMBERS_TO_ORDER_HH
#define NUMBERS_TO_ORDER_HH

#include <iostream>
#include <list>
#include <climits>

class NumbersToOrder
{
    bool repeat; //Used so that a repeat can be detected
    int first;	//The first index in table that is filled
    int last;	//The last index in table that is filled
    int table[65536]; //The Array that holds all the numbers entered
public:
    NumbersToOrder(); // basic constructor
    void printNumbers(); // prints the numbers and whether there is a repeated number
    void numToOrder(std::list<int>); // Sorts the input through hashing and detects if there is repeats
    void run(); // Collects input and detects if there is any errors with the input 
};

#endif
