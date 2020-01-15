/*
  Name: Ian Cowan
  Lab Partner: Jack Pharies
  CSC 341 W20
  P1 Waldo : Graph.cc
  Takes inputs of packages and their dependencies and creates and order of which the
  packages are installed.

  Waldo.cc takes inputs and seperates the inputs into the package and its
  dependencies and puts them into the graph object

  Graph.cc recurses through the packages starting at waldo and tries to find a series of 
  packages that allow for waldo to be installed. At the same time switches inbetween states 
  (not installed, installing, installed) to create an order to the packages

  Graphnode.cc holds the name, dependencies, and state of the package

  Will print "ERROR" if there a dependency that is called that is not in the graph object
  or if the recurssion goes to a graphnode that has a state "installing" 
  (which means that there is a loop).

  Graph.cc handles the recursion, output, and the adding of packages into the graph object.

 */



#include "Graph.hh"

// class Graph:


/*
 Creates a new node with the package name and adds it to adjTable

  Inputs:
    String packageName
  Outputs:
    NONE
  Side Effects:
    Makes a new graphnode with the package name and adds it to the adjTable
*/
void Graph::addPackage(std::string packageName)
{
    if(adjTable.count(packageName) == 0)
    {
        GraphNode newNode = GraphNode(packageName);
        adjTable.insert( {packageName, newNode} );
    }
}



/*
  Takes in a dependency and puts the dependency into the list of dependencies 
  for the correct package

  Inputs:
    String packageName, dependName
  Outputs:
    NONE
  Side Effects:
    Adds package dependencies to the package based on the packageName.
*/
void Graph::addPackageDepend(std::string packageName, std::string dependName)
{
    if(adjTable.count(packageName) > 0)
    {
        GraphNode node = adjTable.find(packageName)->second;
        node.dependencies.push_back(dependName);
        adjTable.find(packageName)->second = node;
    }
}


/*
 Takes a package name and checks to see if that package exists in the 
 adjTable

  Inputs:
    String packageName
  Outputs:
    NONE
  Side Effects:
    NONE
*/
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



/*
 Checks to see if waldo exists in the adjTable, then 
 calls install() starting with waldo

  Inputs:
    NONE
  Outputs:
    NONE
  Side Effects:
    NONE
*/
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



/*
  Recursive method that traverses the adjTable to find a way to install waldo.
  Sets the graphnode states:
  	0 = not installed
  	1 = installing
  	2 = installed
  Calls an error if the recursion returns to the graphnode that has the state 1
  Loops through all the dependencies of the current package if not installed
  If the graphnode is installed, then the current node is pushed onto the 
  installOrder list.



  Inputs:
    String currentPackage
  Outputs:
    NONE
  Side Effects:
    - If the graphnode is installed, then the current node is pushed onto the 
  	  installOrder list.
  	- The state of the currentNode is changed depending on where in the method
  	- isError is changed if an error is detected

*/
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

    // loop - Error
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



/*
 Prints the install order based on the installOrder list.

  Inputs:
    NONE
  Outputs:
    NONE
  Side Effects:
    installOrder loses its contents.
*/
void Graph::printInstallOrder()
{
    unsigned int installOrderSize = installOrder.size();
    for(unsigned int i = 0; i < installOrderSize; i++)
    {
        std::cout << installOrder.back() << std::endl;
        installOrder.pop_back();
    }
}


/*
 Prints the error message

  Inputs:
    NONE
  Outputs:
    NONE
  Side Effects:
    NONE
*/
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