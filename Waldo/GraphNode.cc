/*
  Name: Ian Cowan
  Lab Partner: Jack Pharies
  CSC 341 W20
  P1 Install Waldo :: Graphnode
  The Node object used to store the preintsalations,
  the state of the package,
  and the name of the package.

  Getters and setters for each of the attributes are present.
  Used by graph to store the data of the packages.
  

 */



#include "GraphNode.hh"

// class GraphNode:
GraphNode::GraphNode(std::string packageN)
{
    state = 0;
    packageName = packageN;
}

void GraphNode::setState(int newState)
{
    state = newState;
}

int GraphNode::getState() { return state; }
std::string GraphNode::getPackageName() { return packageName; }
std::list<std::string> GraphNode::getDepends() { return dependencies; }
void GraphNode::setDepends(std::list<std::string> depends) { dependencies = depends; }