/*
CS3500 - Software Engineering Project

Created by Liam de la Cour

Contributed to by: 
Jonathan Hanley
Karol Przestrzelski
Colin Kelleher
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
These functions, which are defined below, will be used by the algorithm to determine the precedence of 
two operators
*/
bool greaterPrecedence(char op1, char op2);
bool equalPrecedence(char op1, char op2);

// The main function of the program
int startInfixToPostfix () {

    // The stack for the operators being read in, that will be processed by the shunting yard algorithm
    char operatorStack[64];
    // This variable will always point to the next available space in the stack, i.e it is initially set to 0
    int operatorStackIndex = 0;

    // This variable will track the number of left brackets currently on stack, to determine if there are mismatched
    // brackets
    int numOfLeftBrackets = 0;
    
    // A pointer to the input text file
    FILE *fpIn = fopen("tokenized.txt", "r");
    // A pointer to the output text file
    FILE *fpOut = fopen("postfixed.txt", "w");

    // A buffer for our inputs
    char buffer[64];



    // Read input file, line by line, storing each line in buffer
    while (fgets(buffer, sizeof(buffer), fpIn) != NULL) {

        // Store the key of each line, i.e I(integer) O(operator) F(float)
        char key = buffer[0];

        // If the input is a Float:
        if (key == 'F') {
            
            // Remove the Key and the space after the key, from the buffer. 
            // Prepending 0's to a number will not affect the value of said number
            buffer[0] = '0';
            buffer[1] = '0';

            // Write the number to the output file
            fprintf(fpOut, "%f ", atof(buffer));
            fflush(fpOut);

        // Else if the input is an Integer:
        }else if (key == 'I') {

            // Remove the Key and the space after the key, from the buffer. 
            // Prepending 0's to a number will not affect the value of said number
            buffer[0] = '0';
            buffer[1] = '0';

            // Write the number to the output file
            fprintf(fpOut, "%d ", atoi(buffer));
            fflush(fpOut);

        // Else if the input is an Operator:
        }else if (key == 'O') {
            
            // Get the operator from the buffer. It is stored at index 2
            char operator = buffer[2];
            
            // While (There are operators on the stack AND ( The operator on top of the stack has greater precedence
            // than the current operator OR the operator on top of the stack has equal precedence to the current operator)
            // AND the operator at the top of the stack is not a left bracket '(' ):
            while ( (operatorStackIndex > 0 && (greaterPrecedence(operatorStack[operatorStackIndex-1], operator) ||
            equalPrecedence(operatorStack[operatorStackIndex-1], operator))
            && operatorStack[operatorStackIndex - 1] != '(') ) {

                // Append the operator on the top of the stack to the output
                fprintf(fpOut, "%c ", operatorStack[operatorStackIndex-1]);
                fflush(fpOut);

                // Move the stack pointer down by one, i.e remove the top element of the stack
                operatorStackIndex -= 1;

            }
            
            // Push the current operator onto the stack
            operatorStack[operatorStackIndex] = operator;
            // Update the stack index
            operatorStackIndex += 1;

        // Else if the input is a Left Bracket:
        }else if (key == 'L') {
            
            // push the left bracket onto the operator stack 
            operatorStack[operatorStackIndex] = buffer[2];
            operatorStackIndex += 1;

            // Increment numOfLeftBrackets
            numOfLeftBrackets += 1;

        // Else if the input is a Right Bracket
        }else if (key == 'R') {

            numOfLeftBrackets -= 1;

            // There is not a matching bracket in the stack
            if (numOfLeftBrackets < 0) {
                return -1;
            }
            
            // While the top of the stack is not a left bracket
            while (operatorStack[operatorStackIndex-1] != '(') {
                // Append the operator on top of the stack to the output file
                fprintf(fpOut, "%c ", operatorStack[operatorStackIndex-1]);
                // Decrement the stack index
                operatorStackIndex -= 1;

                // If there is no matching left bracket in the stack
                if(operatorStackIndex < 0) {
                    return -2;
                }
            }
            
            // If the top of the operator stack is a left bracket
            if (operatorStack[operatorStackIndex-1] == '(') {
                // Remove it, and decrement the operator stack index
                operatorStackIndex -=1;
            }
        }
    }
    
    // After all the inputs are read in, if there are operators on the operator stack:
    if (operatorStackIndex > 0) {
        
        // While the operator stack is not empty:
        while (operatorStackIndex > 0) {
            // Append the top operator on the stack to the output file
            fprintf(fpOut, "%c ", operatorStack[operatorStackIndex-1]);
            fflush(fpOut);
            // Decrement the operator stack index
            operatorStackIndex -= 1;

        }

    }

    // Close the input file
    fclose(fpIn);
    // Close the output file
    fclose(fpOut);

    // End the program
    return 0;
}

/*
Returns true if op1 has greater precedence than op2
*/
bool greaterPrecedence(char op1, char op2) {
    if ((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-')) {
        return false;

    } else if ((op1 == '*' || op1 == '/') && (op2 == '*' || op2 == '/')) {
        return false;
    } else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) {
        return false;
    }

    return true;
}

/*
return true if op1 and op2 have equal precedence
*/
bool equalPrecedence(char op1, char op2) {
    if ((op1 == '+' || op1 == '-') && (op2 == '/' || op2 == '*')) {
        return false;
    }else if ((op1 == '*' || op1 == '/') && (op2 == '-' || op2 == '+')) {
        return false;
    }

    return true;
}

#ifdef NOMAIN
int main(){
    return startInfixToPostfix();
}
#endif
