
#include <iostream>
#include <cstdlib>
#include "LinkedStack.h"
#include "InfixCalc.h"
#include "fstream"
#include <string>
#include <algorithm>
#include <cmath>

int main()
{
    //Declare the test strings
    std::string test2;
    // for a file to be read, please use line 16; while(std::getline(std::cin,test2))
            while (test2 != "0")
            {
                //Display the message
                std::cout<<"\n***** THE INFIX CALCULATOR****"<<std::endl;
                //Display the prompt
                std::cout<<"Enter the valid Infix expression  or 0  to exit: "<<std::endl;
                //Read the Infix expression
                getline(cin, test2);
                test2.erase (std::remove (test2.begin(), test2.end(), ' '), test2.end());
                
                //Create an object of the InfixCalc class
                InfixCalc IfobjTryCalc;
                //Call the function to set the expression
                IfobjTryCalc.setInfix(test2);
                //Call the function to display the results
                IfobjTryCalc.showresult();
            }    
    std::cout<<"\n Good bye and Thank you "<<std::endl;
    //To pause the console window
    //  system("pause");
    //Terminate the main function
    return EXIT_SUCCESS;
}
