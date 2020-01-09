/*
  Name: Ian Cowan
  Lab Partner: Jack Pharies
  CSC 341 W20
  P1 Numbers to Order
  Takes a series of input of numbers −32768 ≤ k ≤ 32767 and sorts the numbers.
  It also checks to see if there are any repeats and prints either "REPEATS" or "NO REPEATS".



  To run this program ... *add how to run here

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




  In this process we chose to be the most effecient possible while sacrificing a given amount of space. 
  Every NumbersToOrder object contains a large array that takes up space.
  This array was made in order for the sorting algorithm to be hashing.
  Given n integers that means that to sort the entire list at worst
  the sorting algorithsm would take a time of O(n)




  
 */

#include "NumbersToOrder.hh"

//class NumbersToOrder:

    /*
      Constructor

      Inputs:
        NONE
      Outputs:
        NONE:
      Side Effects:
        Sets all attributes to their default values.
        Sets all of the values of the array, table, to INT_MIN to allow for checking if
          another value already takes the place of that index while the numbers are being inserted.
      */
    NumbersToOrder::NumbersToOrder()
    {
        repeat = false;
        first = 65535;
        last = 0;
        for(int i = 0; i <= first; i++) { table[i] = INT_MIN; }
    }

    /*
      Prints the numbers from the array to standard out.

      Inputs:
        NONE
      Outputs:
        NONE
      Side Effects:
        Prints to the console.
    */
    void NumbersToOrder::printNumbers()
    {
        // Checks to make sure something has been inputted
        if(first <= last)
        {
            // Prints the numbers and whether or not there is a repeat
            for(int i = first; i <= last; i++)
            {
                if(table[i] != INT_MIN)
                {
                    std::cout << table[i] << std::endl;
                }
            }

            if(repeat)
            {
                std::cout << "REPEATS" << std::endl;
            }
            else
            {
                std::cout << "NO REPEATS" << std::endl;
            }
        }
    }

    /*
      Takes the list of inputs and hashes them into the global attribute tables.
      This method also keeps track of the first and last position of table that has been hashed.
      If there is a collision, the boolean repeat is changed.
      Note: The key is created by adding 32768 to the value of the input.

      Inputs:
        std::list<int> listOfInputs - List of the int inputs from the user
      Outputs:
        NONE
      Side Effects:
        Modify first and last to keep track of the first and last filled locations in the table
          from a user input.
        Modify the attribute table by filling in the user's inputs.
        Modify repeat if a collision is detected while hashing the list of inputs
    */
    void NumbersToOrder::numToOrder(std::list<int> listOfInputs)
    {
        // While we have inputs to work with
        while(! listOfInputs.empty())
        {
            // Get the value from the front and calculate the key
            int value = listOfInputs.front();
            listOfInputs.pop_front();
            int key = value + 32768;

            // Check for repeats and insert as appropriate
            if(table[key] != INT_MIN) { repeat = true; }
            else
            {
                table[key] = value;
                if(key < first)
                {
                    first = key;
                }

                if(key > last)
                {
                    last = key;
                }
            }
        }

        // Print the numbers
        printNumbers();
    }

    /*
      Gathers input from the user and passes it to the numToOrder() method.
      Exits with "ERROR" if the input is invalid.

      Inputs:
        NONE
      Outputs:
        NONE
      Side Effects:
        NONE
    */
    void NumbersToOrder::run()
    {
        // Init variables to get the inputs
        bool error = false;
        int y = 0;
        std::list<int> listOfInputs;

        // Loop until the user presses Ctrl + D or there is an error
        while((! error) && std::cin >> y)
        {
            // Make sure the input is in range
            if(y >= -32768 && y <= 32767)
            {
                listOfInputs.push_back(y);
            }
            else
            {
                // Out of range, we now have an error
                error = true;
            }
        }
        
        // Make sure the user ended and it didn't end because of an error
        if (std::cin.eof())
        {
            // Order the integers and continue with the program
            numToOrder(listOfInputs);
        }
        else
        {
            // If we get here, the user did not end and there is an error
            std::cout << "ERROR" << std::endl;
        }  
    }

/*
  Main function to init the object and run the program.
*/
int main()
{
    // Create a NumbersToOrder object
    NumbersToOrder numObject = NumbersToOrder();

    // Run the program
    numObject.run();
    
    return 0;
}

