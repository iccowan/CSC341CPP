#include "Graph.cc"
#include <string>

int main()
{
    Graph myGraph = Graph();
    myGraph.addPackage("waldo");
    myGraph.addPackageDepend("waldo", "gpp");
    myGraph.addPackageDepend("waldo", "libc");
    myGraph.addPackage("gpp");
    myGraph.addPackageDepend("gpp", "libc");
    myGraph.addPackage("libc");
    myGraph.addPackageDepend("libc", "waldo");
    myGraph.printPackagesAndDepends();
    return 0;
}