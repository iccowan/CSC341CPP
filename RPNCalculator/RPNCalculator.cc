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

#include "RPNCalculator.hh"

// class RPNCalculator:
/*
 Prints the message "ERROR" and clears the stack of all items in it.

  Inputs:
    NONE
  Outputs:
   	ERROR message
  Side Effects:
    Clears any remaining items from the stack

*/
void RPNCalculator::error()
{
    std::cout << "ERROR" << std::endl;
    stack.clear();
}


/*
 Adds the two top numbers of the stack together and 
 puts the sum back on top of the stack.
 Calls error() if there are less than two numbers on the stack.
 Called when "+" is the input.

  Inputs:
    NONE
  Outputs:
   	NONE
  Side Effects:
    Takes the two numbers at the top of the stack and adds them together.
    The sum of the two numbers is then placed on the top of the stack.

*/
void RPNCalculator::add()
{
    if(stack.size() < 2)
    {
        error();
        return;
    }

    int num1 = stack.front();
    stack.pop_front();
    int num2 = stack.front();
    stack.pop_front();

    stack.push_front(num1 + num2);
}


/*
 Subtracts the first number of the stack from the second number and
 puts the difference back on top of the stack.
 Calls erro() if there are less than two numbers on the stack.
 Called when "-" is the input.

  Inputs:
    NONE
  Outputs:
   	NONE
  Side Effects:
    Subtracts the first number of the stack from the second number.
 	puts the difference back on top of the stack.

*/
void RPNCalculator::subtract()
{
    if(stack.size() < 2)
    {
        error();
        return;
    }

    int num1 = stack.front();
    stack.pop_front();
    int num2 = stack.front();
    stack.pop_front();

    stack.push_front(num2 - num1);
}


/*
 Multiplies the two top numbers of the stack together and 
 puts the product back on top of the stack.
 Calls error() if there are less than two numbers on the stack.
 Called when "*" is the input.

  Inputs:
    NONE
  Outputs:
   	NONE
  Side Effects:
    Takes the two numbers at the top of the stack and multiplies them together.
    The product of the two numbers is then placed on the top of the stack.

*/
void RPNCalculator::multiply()
{
    if(stack.size() < 2)
    {
        error();
        return;
    }

    int num1 = stack.front();
    stack.pop_front();
    int num2 = stack.front();
    stack.pop_front();

    stack.push_front(num1 * num2);
}


/*
 Divides the second number of the stack by the first number and 
 puts the quotient back on top of the stack.
 Calls error() if there are less than two numbers on the stack.
 Called when "/" is the input.

  Inputs:
    NONE
  Outputs:
   	NONE
  Side Effects:
    Divides the second number of the stack by the first number and 
 	puts the quotient back on top of the stack.

*/
void RPNCalculator::divide()
{
    if(stack.size() < 2)
    {
        error();
        return;
    }

    float num1 = (float) stack.front();
    stack.pop_front();
    float num2 = (float)stack.front();
    stack.pop_front();

    // Divide by zero error
    if((int) num1 == 0)
    {
        error();
        return;
    }

    int result = floor(num2 / num1);

    stack.push_front(result);
}



/*
 Swaps the top two numbers and places them back on the stack.
 Calls error() if there are less than two numbers on the stack.
 Called when "s" is the input.

  Inputs:
    NONE
  Outputs:
   	NONE
  Side Effects:
    Swaps the first two numbers of the stack with eachother.

*/
void RPNCalculator::swap()
{
    if(stack.size() < 2)
    {
        error();
        return;
    }

    int num1 = stack.front();
    stack.pop_front();
    int num2 = stack.front();
    stack.pop_front();

    stack.push_front(num1);
    stack.push_front(num2);
}


/*
 Duplicates the first number of the stack and places the duplicate
 on the top of the stack
 Calls error() if there are less than one number on the stack.
 Called when "d" is the input

  Inputs:
    NONE
  Outputs:
   	NONE
  Side Effects:
    Dulicates the value of the first number and puts the duplicate
    on the top of the stack.

*/
void RPNCalculator::dupe()
{
    if(stack.size() < 1)
    {
        error();
        return;
    }

    stack.push_front(stack.front());
}


/*
 Outputs the top of the stack. 
 Calls error() if there is not one item on the stack.
 Called when "=" is the input

  Inputs:
    NONE
  Outputs:
   	The last number on the stack
  Side Effects:
    Clears the stack of the last number, making the stack empty.

*/
void RPNCalculator::calculate()
{
    if(stack.size() != 1)
    {
        error();
        return;
    }

    std::cout << stack.front() << std::endl;
    stack.clear();
}



/*
 Checks to make sure that the input is a valid operator.
 If it is a valid operator, the corresponding method is called.
 If the input is not a valid operator, FALSE is returned and 
 checkInteger() is called.

  Inputs:
    String input (the inputed value)
  Outputs:
   	Boolean (whether the value is legal or not)
  Side Effects:
    NONE

*/
bool RPNCalculator::checkSymbol(std::string input)
{
    // Checks the symbol and calls the appropriate method
        if(input == "+")
        {
            add();
            return true;
        }
        else if(input == "-")
        {
            subtract();
            return true;
        }
        else if(input == "*")
        {
            multiply();
            return true;
        }
        else if(input == "/")
        {
            divide();
            return true;
        }
        else if(input == "s")
        {
            swap();
            return true;
        }
        else if(input == "d")
        {
            dupe();
            return true;
        }
        else if(input == "=")
        {
            calculate();
            return true;
        }

        return false;
}


/*
 Checks to make sure that the input is a valid integer (including negatives).
 If it is a valid integer, the integer is pushed onto the stack.
 If the input is not a valid integer, error() is called.

  Inputs:
    String input (the inputed value)
  Outputs:
   	NONE
  Side Effects:
    If the input is an integer, it is pushed onto the front of the stack.

*/
void RPNCalculator::checkInteger(std::string input)
{
    int start = 0;
    if(input[0] == '-')
    {
        start = 1;
    }

    if(input == "")
    {
        error();
        return;
    }

    for(int i = start; i < (int) input.length(); i++)
    {
        if(! std::isdigit(input[i]))
        {
            error();
            return;
        }
    }

    stack.push_front(std::stoi(input));
}


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
void RPNCalculator::run()
{
    std::string input;
    std::getline(std::cin, input);

    while(! std::cin.eof())
    {
        if(! checkSymbol(input))
        {
            checkInteger(input);
        }

        std::getline(std::cin, input);
    }
}


/*
  Main function to init the object and run the program.
*/
int main()
{
	// creates the RPNCalculator object
    RPNCalculator calculator = RPNCalculator();

    // runs the calculator
    calculator.run();


    return 0;
}
