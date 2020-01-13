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
    void addPackage(std::string);
    void addPackageDepend(std::string, std::string);
    bool isPackageInGraph(std::string);
    void getInstallOrder();
private:
    void install(std::string);
    void printInstallOrder();
    void error();
    //void printPackagesAndDepends();
};

#endif