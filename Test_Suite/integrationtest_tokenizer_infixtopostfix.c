/*
CS3500 - Software Engineering Project


INTEGRATION TEST - Tokenizer & Infixtopostfix

Colin Kelleher
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
*/


/*
Include statements
*/
#include <ctap.h>
#include <tokenizer.h>
#include <infixtopostfix.h>
#include "common.h"

/*
Creating sample inputs
*/
char *inputs[] = {
    "14 + 52",
    "12.5*(12+5)",
    "(10 * 10) + 3 -2",
    "1* 1 * 12 - 4 / (1+1)",
    "0 * 0 + 1"
};

/*
Creating correct outputs for the sample inputs
*/
char *outputs[] = {
    "14 52 + \n",
    "12.500000 12 5 + * \n",
    "10 10 * 3 + 2 - \n",
    "1 1 * 12 * 4 1 1 + / - \n",
    "0 0 * 1 + \n"
};

void _create_input(int test_num){
    createTextFile("input.txt", inputs[test_num]);
}

/*
Running the Tokenizer and InfixToPostfix converter
and ensursing that the inputs/outputs are appropriate
*/
void test_integration_tokenizer_infixtopostfix(){
    for (int test_num = 0; test_num < 5; test_num++){
        _create_input(test_num);
        startTokenizer();
        printf(" ");
        startInfixToPostfix();
        ok(compareTextInFile("postfixed.txt", outputs[test_num]) == 0, "Success on input %s", inputs[test_num]);
    }
}

/*
Running the above tests
*/
TESTS{
    test_integration_tokenizer_infixtopostfix();
}
