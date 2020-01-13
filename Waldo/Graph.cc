#include "Graph.hh"

// class Graph:

void Graph::addPackage(std::string packageName)
{
    if(adjTable.count(packageName) == 0)
    {
        GraphNode newNode = GraphNode(packageName);
        adjTable.insert( {packageName, newNode} );
    }
}

void Graph::addPackageDepend(std::string packageName, std::string dependName)
{
    if(adjTable.count(packageName) > 0)
    {
        GraphNode node = adjTable.find(packageName)->second;
        node.dependencies.push_back(dependName);
        adjTable.find(packageName)->second = node;
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

void Graph::getInstallOrder()
{
    if(adjTable.count("waldo") == 0)
    {
        error();
        isError = false;
        return;
    }

    install("waldo");
    if(! isError)
    {
        printInstallOrder();
    }
    else
    {
        error();
    }
}

void Graph::install(std::string currentPackage)
{
    // Base cases:
    //  1 - Error; Cycle in the graph and uninstallable
    //  2 - Dependency already installed
    //  0 - Begin installation of current package & recurse through children if applicable

    if(isError)
    {
        return;
    }

    if(adjTable.count(currentPackage) == 0)
    {
        isError = true;
        return;
    }

    // Get the GraphNode from the returned pair
    GraphNode currentNode = adjTable.find(currentPackage)->second;

    if(currentNode.getState() == 1)
    {
        isError = true;
        return;
    }
    else if(currentNode.getState() == 2)
    {
        return;
    }
    else
    {
        // Begin the installation
        currentNode.setState(1);
        adjTable.find(currentPackage)->second = currentNode;

        std::list<std::string> dependencies = currentNode.getDepends();
        unsigned int dependenciesSize = dependencies.size();
        for(unsigned int i = 0; i < dependenciesSize; i++)
        {
            install(dependencies.front());
            dependencies.pop_front();

            if(isError)
            {
                return;
            }
        }
    }

    installOrder.push_front(currentPackage);
    currentNode.setState(2);
    adjTable.find(currentPackage)->second = currentNode;
    return;
}

void Graph::printInstallOrder()
{
    unsigned int installOrderSize = installOrder.size();
    for(unsigned int i = 0; i < installOrderSize; i++)
    {
        std::cout << installOrder.back() << std::endl;
        installOrder.pop_back();
    }
}

void Graph::error()
{
    std::cout << "ERROR" << std::endl;
}

/*
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
 */