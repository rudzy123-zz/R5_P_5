/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Testing the ArrayStack class.
 *
 *  Adapted from page 244 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 28 Feb 2018
 *
 *  @version 7.0 */

#include <iostream>
#include <string>
#include <new>

#include "LinkedStack.h"

int main() {
    
    using StackStrPtr = StackInterface<std::string>*;
    
    try {
        StackStrPtr stackPtr(new LinkedStack<std::string>() );
        
        std::string anItem("");
        char more;
        
        do {
            std::cout << "Enter a word (no whitespace): ";
            
            std::cin >> anItem;
            
            stackPtr->push(anItem);
            
            std::cout << "More items to enter? ";
            
            std::cin >> more;
        } while (more == 'y' || more == 'Y');
        
        std::cout << "\nThe stack:"
        << std::endl;
        
        while (!stackPtr->isEmpty() ) {
            std::cout << stackPtr->peek()
            << std::endl;
            stackPtr->pop();
        }
        
        std::cout << "Try to peek at the empty stack:"
        << std::endl;
        
        if (!stackPtr->isEmpty() ) {
            stackPtr->peek();
        }
        else {
            std::cout << "Cannot peek at an empty stack.\n"
            << std::endl;
        }
        
        std::cout << "All done!"
        << std::endl;
    }
    catch (const std::bad_alloc&) {
        std::cerr << "ERROR: Ran out of memory."
        << std::endl;
    }
    
    return EXIT_SUCCESS;
}
