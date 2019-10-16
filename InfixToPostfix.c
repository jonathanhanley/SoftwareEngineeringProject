#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


bool greaterPrecedence(char op1, char op2);
bool equalPrecedence(char op1, char op2);

int main (int argc, char** argv) {


    char operatorStack[64];
    int operatorStackIndex = 0;

    FILE *fpIn = fopen("tokenized.txt", "r");

    FILE *fpOut = fopen("postfixed.txt", "w");

    char buffer[64];



    // Read input file, line by line, storing each line in buffer
    while (fgets(buffer, sizeof(buffer), fpIn) != NULL) {

        // Store the key of each line, i.e I(integer) O(operator) F(float)
        char key = buffer[0];


        if (key == 'F') {
            printf("Float\n");

            buffer[0] = '0';
            buffer[1] = '0';

            fprintf(fpOut, "%f ", atof(buffer));
            fflush(fpOut);

        }else if (key == 'I') {

            printf("Integer\n");

            buffer[0] = '0';
            buffer[1] = '0';

            fprintf(fpOut, "%d ", atoi(buffer));
            fflush(fpOut);

        }else if (key == 'O') {

            printf("Operator\n");

            char operator = buffer[2];

            while ( (operatorStackIndex > 0 && (greaterPrecedence(operatorStack[operatorStackIndex-1], operator) ||
            equalPrecedence(operatorStack[operatorStackIndex-1], operator))
            && operatorStack[operatorStackIndex - 1] != '(') ) {

                fprintf(fpOut, "%c ", operatorStack[operatorStackIndex-1]);
                fflush(fpOut);

                operatorStackIndex -= 1;

            }

            operatorStack[operatorStackIndex] = operator;
            operatorStackIndex += 1;


        }else if (key == 'L') {

            operatorStack[operatorStackIndex] = buffer[2];
            operatorStackIndex += 1;

        }else if (key == 'R') {

            while (operatorStack[operatorStackIndex-1] != '(') {
                fprintf(fpOut, "%c ", operatorStack[operatorStackIndex-1]);
                operatorStackIndex -= 1;
            }

            if (operatorStack[operatorStackIndex-1] == '(') {
                operatorStackIndex -=1;
            }
        }
    }

    if (operatorStackIndex > 0) {

        while (operatorStackIndex > 0) {

            fprintf(fpOut, "%c ", operatorStack[operatorStackIndex-1]);
            fflush(fpOut);

            operatorStackIndex -= 1;

        }

    }

    fclose(fpIn);
    fclose(fpOut);


    return 0;
}

bool greaterPrecedence(char op1, char op2) {
    // Return true if op1 has greater precedence than op2

    if ((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-')) {

        return false;

    } else if ((op1 == '*' || op1 == '/') && (op2 == '*' || op2 == '/')) {

        return false;
    } else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) {

        return false;
    }

    return true;
}

bool equalPrecedence(char op1, char op2) {
    // return true if op1 and op2 have equal precedence

    if ((op1 == '+' || op1 == '-') && (op2 == '/' || op2 == '*')) {

        return false;
    }else if ((op1 == '*' || op1 == '/') && (op2 == '-' || op2 == '+')) {

        return false;
    }

    return true;
}
