#ifndef GRAPH_NODE_HH
#define GRAPH_NODE_HH

#include <iostream>

class GraphNode
{
    // attributes
    std::string packageName;
    int state; // 0 - uninstalled; 1 - installing; 2 - installed
public:
    std::list<std::string> dependencies;

    // methods
public:
    // getters and setters
    GraphNode(std::string); // constructor
    void setState(int); // Sets the state of the node
    int getState(); // Gets the state of the node
    std::string getPackageName(); // Gets the package name of the node
    std::list<std::string> getDepends(); // Gets the dependencies of the package
    void setDepends(std::list<std::string>); // Sets the dependencies of the package
};

#endif
