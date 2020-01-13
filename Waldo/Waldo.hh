// Class declaration file for Waldo

#ifndef WALDO_HH
#define WALDO_HH

#include <iostream>
#include <string>
#include <vector>
#include "Graph.cc"

class Waldo
{
    // attributes
    Graph graph = Graph();

public:
    Waldo() {} // basic constructor
    // methods
    void run();
    void insertIntoGraph(std::string);
    std::list<std::string> splitString(std::list<std::string>, std::string, char);
};

#endif
