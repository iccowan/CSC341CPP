/*
  Name: Ian Cowan
  Lab Partner: Jack Pharies
  CSC 341 W20
  P1 RPN Calculator
  Takes a number of inputs and calculates the total depending on what is given.

  Will print "ERROR" if the input incorrect or if the operation could not be exectuted

  Valid inputs:
   - Any integer, positive or negative.
   - Operators:
   	- + (adds the two top numbers)
   	- - (subtracts the two top numbers)
   	- * (multiplies te two top numbers)
   	- / (divides the two top numbers)
   	- d (duplicates the top number)
  	- s (swaps the two top numbers)
   	- = (outputs the 1 remaining number)


  To run this program go to console and type "make" press enter and then "./calc" and press enter
  To end the program press "control -D" or whatever command the OS uses to determine EOF
  Note that in order to do this the makefile, header, and .cc file must all be in the same directory

  Example:

    Input:
          10
          10
          +
          =

    Output:
          20


  Test cases are stored in the folder called "tests"
  The test has a text file named test_in, test_out, and test_sol
  test_in is the input we are testing
  test_out is the output that the program gives
  test_sol is our predicted output that is compared against test_out
  Due to the program not stopping at the "=", we ran all test from a single .txt file
  The file test_explain has the test case and a description of every test that is run
  Tests were preformed by running the command:
  "cat test_in.txt | ./numbers >test_out.txt" then "diff test_out.txt test_sol.txt"

  We handle all the math after each input is put in,
  therefore we only have to deal with a very smal amount
  of items within the list at any given moment.
  This also allows our program to be very effiecnt.

  To add any input to the list is O(1).
  To see the total of the calculation is O(1).
  The other operators depend on how many of them are inputed.
  Therefore the time complexity of the operators are O(n),
  where n is the total amount of operators inputted


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

void Waldo::insertIntoGraph(std::string input)
{
    std::list<std::string> output;

    std::list<std::string> packagesAndDepends = splitString(output, input, ' ');

    std::string packageName = packagesAndDepends.front();
    packagesAndDepends.pop_front();
    graph.addPackage(packageName);

    unsigned int packagesSize = packagesAndDepends.size();
    for (unsigned int i = 0; i < packagesSize; i++) {
        graph.addPackageDepend(packageName, packagesAndDepends.front());
        packagesAndDepends.pop_front();
    }
}

std::list<std::string> Waldo::splitString(std::list<std::string> output, std::string input, char delimiter)
{
    std::string nextString;
    for(unsigned int i = 0; i < input.length(); i++)
    {
        if(input[i] == delimiter)
        {
            output.push_back(nextString);
            nextString = "";
        }
        else
        {
            nextString = nextString + input[i];
        }
    }
    output.push_back(nextString);

    return output;
}

int main()
{
    Waldo installWaldo = Waldo();
    installWaldo.run();

    return 0;
}
