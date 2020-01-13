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
    GraphNode(std::string);
    void setState(int);
    void install(); // Puts this
    int getState();
    std::string getPackageName();
    std::list<std::string> getDepends();
    void setDepends(std::list<std::string>);
};

#endif