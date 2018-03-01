//
//  InfixCalc.h
//  Project4
//
//  Created by Rudolf Musika on 2/27/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//

#ifndef InfixCalc_h
#define InfixCalc_h

#include <string>
#include "LinkedStack.h"
#include "PrecondViolatedExcept.hpp"

class InfixCalc
{
    //Private scope stack variable to store the items
private:
    /*Declare the stack with integar type to store the operands of the expression*/
    LinkedStack<char> opStack;
    /*Declare the stack to hold the operands and intermediate values*/
    LinkedStack <int> valStack;
    /*String type variable to store the Infix expression*/
    std::string Infix;
    //Variable to store the result
    float result;
    //Public scope items of the class
public:
    //Method to set the postfix expression
    void setInfix(std::string inp);

    int GetPrecedence(char in_opr);
    int InfixEval();
    void showresult();
    void Execute();
};
#include "InfixCalc.cpp"
#endif /* InfixCalc_h */
