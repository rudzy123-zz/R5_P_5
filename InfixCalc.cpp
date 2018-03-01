
#include "StackInterface.h"
#include "LinkedStack.h"
#include "PrecondViolatedExcept.hpp"
#include <stdexcept>
#include <cmath>
using namespace std;
/***********************************************/

/*Method to evaluate the infix expression by using the algorithm given in the problem */
int InfixCalc::InfixEval()
    {
        //The for loop to process the string
        for (int itr =0; itr<Infix.length();itr++)
        {
            /*The character variable to store the infix characters*/
            char cha = Infix[itr];
            /*Initialize a temporary integar variable*/
            int temp = 0;
            /*The switch statement to handle the different characters of the infix expression*/
        
            switch(cha)
            {
                    /*If the character is a single digit operand*/
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    /*Convert the character into integar type operand,
                     -In ascii code numbers start at 48, so this it*/
                    temp = (int)(cha)-48;
                    /*Push the operand into the stack*/
                    valStack.push(temp);
                    //break the case statement
                    break;
                    /*If the character is an open parenthesis*/
                case '(':
                    /*Push the parenthesis into the stack*/
                    opStack.push(cha);
                    //break the case statement
                    break;
                    //If the character is an operator
                case '*':
                case '/':
                case '+':
                case '-':
                    //If the opStack is empty
                    if(opStack.isEmpty() or GetPrecedence(cha)>GetPrecedence(opStack.peek()))
                    {
                        /*If the precedence of operator at the top of the stack is less than current operator*/
                        opStack.push(cha);
                    }
//                    /*If the precedence of operator at the top the stack is less than current operator*/
//                    else if (GetPrecedence(cha)>GetPrecedence(opStack.peek()))
//                    {
//                        /*Push the operator into the operator stack*/
//                        opStack.push(cha);
//                    }
                    /*If the stack top operator has higher precedence*/
                    else
                    {
                        /*The while loop to pop the higher precedence operator from the operator stack*/
                        while(!opStack.isEmpty() && GetPrecedence(cha)<= GetPrecedence(opStack.peek()))
                        {
                            /*Execute the function Execute()*/
                            Execute();
                        }
                            /*Push the operator to the operator stack*/
                            opStack.push(cha);
                        
                    }
                    //break the case statement
                    break;
                    /*If the character is an closing parenthesis*/
                case ')':
                    /*While the stack top is not an open parenthesis*/
                    while (opStack.peek() != '(')
                    {
                        /*Execute the function Execute()*/
                        Execute();
                    }
                    /*Pop the open parenthesis from the stack*/
                    opStack.pop();
                    //break the case statement
                    break;
            }// End the switch
        }//End the for loop
        
        //Pop while the stack becomes empty
        while(!opStack.isEmpty()){
            //Execute the Execute method
            Execute();
        //Set the evaluation result
        }
        result = valStack.peek();

   return result;
    }//End the method

//Method Execute to perform the operations
void InfixCalc::Execute()
    {
        //Retrieve the second operand
        int operand2 = valStack.peek();
        //Pop the stack
        valStack.pop();
        //Retrieve the first operand
        int operand1 = valStack.peek();
        //Pop the stack
        valStack.pop();
        //Retrieve the operator
        char op = opStack.peek();
        //Pop the stack
        opStack.pop();
        //Initialize the temporary result variable
        int tempresult = 0;
        //Switch to deal with different operations
        switch(op)
            {
                //Perform the operation
            case '+':
                tempresult = operand1 + operand2;
                //Break the case
                break;
            case '-':
                //Perform  the operation
                tempresult = operand1 - operand2;
                //Break the case
                break;
                //If the operation is multiplication
            case '*':
                //Perform the operation
                tempresult = operand1*operand2;
                //Break the case
                break;
                //If the operation is division
            case '/':
                //Perform the operation
                try{
                if (operand2 == 0){
                    throw std::overflow_error("Divide by zero exception");
                    }
                    tempresult = operand1/operand2;
                }
                catch (std::overflow_error e) {
                    std::cout << e.what() << " -> ";
                                }
                break;
                }

        /*Push the result into the operand stack*/
        valStack.push(tempresult);
    }// End the function Execute

/*Function to return the precedence of an operator*/
int InfixCalc::GetPrecedence(char in_opr)
    {
        /*Initialize the integer variable to set the precedence*/
        int prece = -1;
        //Switch to handle difference operators
        switch(in_opr)
        {
                //In the case of '('
            case '(':
                //Set precedence as 0
                prece = 0;
                //Break the case
                break;
                //In the case of - and +
            case '+':
            case '-':
                //Set precedence as 1
                prece = 1;
                //Break the case
                break;
            case '*':
            case '/':
                //Set precedence as 2
                prece = 2;
                //Break the case
                break;
        }
        //Return the obtained precedence value
        return prece;
    }// End the function GetPrecedence


void InfixCalc::showresult()
    {
        //Display the result
        std::cout<<"The result of the evalutation of "<<InfixEval()<<std::endl;
    }//End the class definition
void InfixCalc::setInfix(std::string inp)
    {
    Infix = inp;
    }// End the method definition

/***********************************************/

