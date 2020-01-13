#include "Graph.hh"

// class Graph:

void Graph::addPackage(std::string packageName)
{
    if(! (adjTable.count(packageName) > 0))
    {
        std::list<GraphNode> newList;
        adjTable.insert( {packageName, newList} );
    }
}

void Graph::addPackageDepend(std::string packageName, std::string dependName)
{
    if(adjTable.count(packageName) > 0)
    {
        GraphNode newNode = GraphNode(dependName);
        adjTable.find(packageName)->second.push_back(newNode);
    }
}

bool Graph::isPackageInGraph(std::string packageName)
{
    if(adjTable.count(packageName) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Graph::printPackagesAndDepends()
{
    for(std::unordered_map<std::string, std::list<GraphNode> >::iterator it = adjTable.begin(); it != adjTable.end(); ++it) {
        std::cout << it->first << " - ";
        for (GraphNode i : it->second) {
            std::cout << i.getPackageName() << ", ";
        }
        std::cout << std::endl;
    }


}