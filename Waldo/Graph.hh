#ifndef GRAPH_HH
#define GRAPH_HH

#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include "GraphNode.cc"

class Graph
{
    // attributes
    std::unordered_map<std::string, GraphNode> adjTable;
    std::list<std::string> installOrder;
    bool isError = false;

    // methods
public:
    Graph() {}
    void addPackage(std::string); // adds a graphnode
    void addPackageDepend(std::string, std::string); // adds a dependency
    bool isPackageInGraph(std::string); // checks if a package exists
    void getInstallOrder(); // starts the recursion
private:
    void install(std::string); // recursion to find an install order
    void printInstallOrder(); // prints the install order
    void error(); // prints error message
    //void printPackagesAndDepends();
};

#endif