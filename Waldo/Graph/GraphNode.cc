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