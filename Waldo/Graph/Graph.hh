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
    std::unordered_map<std::string, std::list<GraphNode> > adjTable;

    // methods
public:
    Graph() {}
    void addPackage(std::string);
    void addPackageDepend(std::string, std::string);
    bool isPackageInGraph(std::string);
    void printPackagesAndDepends();
};

#endif