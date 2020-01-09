// Class declaration file for NumbersToOrder

#ifndef NUMBERS_TO_ORDER_HH
#define NUMBERS_TO_ORDER_HH

#include <iostream>
#include <list>
#include <climits>

class NumbersToOrder
{
    bool repeat;
    int first;
    int last;
    int table[65536];
public:
    NumbersToOrder();
    void printNumbers();
    void numToOrder(std::list<int>);
    void run();
};

#endif
