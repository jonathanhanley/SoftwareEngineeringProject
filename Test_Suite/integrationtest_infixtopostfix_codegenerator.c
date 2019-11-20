/*
CS3500 - Software Engineering Project


INTEGRATION TEST - Infixtopostfix & Code Generator

Colin Kelleher
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
*/

/*
Include statements
*/
#include <ctap.h>
#include <infixtopostfix.h>
#include <codegenerator.h>
#include "common.h"

/*
Creating inputs, indexes and the number of tests
*/
int num_tests = 1;

char *inputs[] = {
    "I 1\nO *\nI 2\nO +\nI 3\n",
    "F 2.2\nO +\nI 5\n",
    "I 100\nO -\nF 3.2\n"
};
/*
Creating outputs corresponding to the above inputs
*/
char *outputs[] = {
    "LOADINT 1\0\nLOADINT 2\0\nMUL \0\nLOADINT 3\0\nADD \0\n",
    "LOADFLOAT 2.200000\0\nLOADINT 5\0\nADD \0\n",
    "LOADINT 100\0\nLOADFLOAT 3.200000\0\nSUB \0\n"
};
/*
Creating the appropriate inputs
in the correct file to resemble the working version
Inputs are written to this file in the correct format
*/
void _create_input(int test_num){
    createTextFile("tokenized.txt", inputs[test_num]);
}

/*
Used to check if the output matches the input as defined above
*/
void output_matches_input(int test_num){
    ok(compareTextInFile("codegenerated.txt", outputs[test_num]) == 1, "TEST %d", test_num);

}
/*
Creating the appropriate inputs
Running the InfixToPostfix converter and CodeGenerator
Then checking to make sure the outputs match the expected output
*/
void test_integration_infixtopostfix_codegenerator(){
    for(int i = 0; i < num_tests; i++){
        _create_input(i);
        startInfixToPostfix();
        printf(" ");
        startCodeGenerator();
        output_matches_input(i);
    }
}

/*
Running the above tests
*/
TESTS{
    test_integration_infixtopostfix_codegenerator();
}
