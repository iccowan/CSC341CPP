/*
  Name: Ian Cowan
  Lab Partner: Jack Pharies
  CSC 341 W20
  P1 Waldo : waldo.cc
  Takes inputs of packages and their dependencies and creates and order of which the
  packages should be installed.

  Waldo.cc takes inputs and seperates the inputs into the package and its
  dependencies and puts them into the graph object

  Graph.cc recurses through the packages starting at waldo and tries to find a series of 
  packages that allow for waldo to be installed. At the same time switches inbetween states 
  (not installed, installing, installed) to create an order to the packages

  Graphnode.cc holds the name, dependencies, and state of the package

  Will print "ERROR" if the input does not include a package named "waldo" and if the package
  "waldo" cannot be installed

  Valid inputs:
  Any string of inputs. The first name is the package name followed by its dependencies.
  Example: waldo packageA packageB
  waldo is the package name
  packageA and packageB are the dependencies of waldo


  To run this program go to console and type "make" press enter and then "./waldo" and press enter
  To end the program press "control -D" or whatever command the OS uses to determine EOF
  Note that in order to do this the makefile, header, and .cc file must all be in the same directory

  Example:

    Input:
          waldo a b
          a b
          b

    Output:
          b
          a
          waldo


  After the input is finished, the graphs "install" method is called and 
  the graph object handles the rest of the work.

  Test cases are stored in the folder called "tests"
  Each test has a text file named test_in, test_out, and test_sol
  test_in is the input we are testing
  test_out is the output that the program gives
  test_sol is our predicted output that is compared against test_out
  Tests were preformed by running the command:
  "cat test_in.txt | ./waldo >test_out.txt" then "diff test_out.txt test_sol.txt"

 */

#include "Waldo.hh"

// class Waldo:

/*
 Gathers the input and calls the checkSymbol() and checkInteger() methods.
 Only stops gathering inputs if EOF is detected.

  Inputs:
    NONE
  Outputs:
   	NONE
  Side Effects:
    NONE

*/
void Waldo::run()
{
    // Get the input
    std::string input;
    std::getline(std::cin, input);

    // Run while we are not at EOF
    while(! std::cin.eof())
    {
        // Make sure the input is not empty
        if(input != "" || input != " ")
        {
            // Insert into the graph
            insertIntoGraph(input);
        }

        std::getline(std::cin, input);
    }

    graph.getInstallOrder();
}




/*
 Takes an input and calls splitString() to splice the string between each " ".
 Then calls graphs addPackage to create a new graphnode with the package name 
 and al the dependencies.

  Inputs:
    String input
  Outputs:
    NONE
  Side Effects:
    Makes a new graphnode with the package name and the dependencies 
    and adds the node onto the graph object
*/
void Waldo::insertIntoGraph(std::string input)
{
    std::list<std::string> output;

    std::list<std::string> packagesAndDepends = splitString(output, input, ' ');

    std::string packageName = packagesAndDepends.front();
    packagesAndDepends.pop_front();
    graph.addPackage(packageName);

    unsigned int packagesSize = packagesAndDepends.size();

    // adding the dependencies
    for (unsigned int i = 0; i < packagesSize; i++) {
        graph.addPackageDepend(packageName, packagesAndDepends.front());
        packagesAndDepends.pop_front();
    }
}


/*
 Takes an input and splits the string on the character " ".
 Puts the split string into the list output.

  Inputs:
    String input, character delimiter (" ")
  Outputs:
    output - a list of strings formed from input
  Side Effects:
    NONE

*/
std::list<std::string> Waldo::splitString(std::list<std::string> output, std::string input, char delimiter)
{
    std::string nextString;

    // go through each character, add the nextString, and push onto list when " "
    for(unsigned int i = 0; i < input.length(); i++)
    {
        if(input[i] == delimiter)
        {
            // Once we hit our delimeter, let's add to the list
            // and set the string back to the empty string
            output.push_back(nextString);
            nextString = "";
        }
        else
        {
            // If we aren't at our delimeter, add the character to the string
            nextString = nextString + input[i];
        }
    }
    output.push_back(nextString);

    return output;
}


/*
Main function
creates the installWaldo object and calls run
*/
int main()
{

    // creates the object
    Waldo installWaldo = Waldo();

    //runs the project
    installWaldo.run();

    return 0;
}
