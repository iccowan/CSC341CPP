/*
  Name: Ian Cowan
  Lab Partner: Jack Pharies
  CSC 341 W20
  P1 Numbers to Order
  Takes a series of input of numbers −32768 ≤ k ≤ 32767 and sorts the numbers.
  It also checks to see if there are any repeats and prints either "REPEATS" or "NO REPEATS".


  To run this program go to console and type "make" press enter and then "./numbers" and press enter
  Failure to type in the correct input will result in an Error message being outputed
  Note that in order to do this the makefile, header, and .cc file must all be in the same directory

  Example:

    Input:
          10
          20
          15
          30
          15
          25
    Output:
          10
          15
          20
          25
          30
          REPEATS


  Test cases are stored in the folders called "tests"
  Each test has a text file named test#_in, test#_out, and test#_sol
  # refers to the number of the test
  test_in is the input we are testing
  test_out is the output that the program gives
  test_sol is our predicted output that is compared against test_out
  Tests were preformed by running the command:
  "cat test_in.txt | ./numbers >test_out.txt" then "diff test_out.txt test_sol.txt"


  In this process we chose to be the most effecient possible while sacrificing
  a given amount of space.
  Every NumbersToOrder object contains a large array that takes up space.
  This array was made in order for the sorting algorithm to be hashing.
  Given n integers that means that to sort the entire list at worst
  the sorting algorithsm would take a time of O(n)


 */

#include "RPNCalculator.hh"

// class RPNCalculator:

void RPNCalculator::error()
{
    std::cout << "ERROR" << std::endl;
    stack.clear();
}

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

void RPNCalculator::dupe()
{
    if(stack.size() < 1)
    {
        error();
        return;
    }

    stack.push_front(stack.front());
}

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

void RPNCalculator::checkInteger(std::string input)
{
    int start = 0;
    if(input[0] == '-')
    {
        start = 1;
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

int main()
{
    RPNCalculator calculator = RPNCalculator();
    calculator.run();
}