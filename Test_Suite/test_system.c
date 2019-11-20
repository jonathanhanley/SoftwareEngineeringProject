/*
CS3500 - Software Engineering Project


UNIT TEST - Virtual Machine

Colin Kelleher
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
*/


/*
Include statements
*/
#include <ctap.h>
#include "virtualmachine.h"
#include "stack.h"
#include "common.h"
#include "codegenerator.h"
#include "tokenizer.h"
#include "infixtopostfix.h"

// #define TESTS int main()
// #define ok(a, b, c) if (a) printf(b, c);

/*
Creating an index to keep track of the number of iterations
of the input and output
Also keeping track of the number of tests
*/
int num_tests = 7;

/*
Creating various inputs as test cases
*/
char *inputs[] = {
    "14 + 52",
    "10 - 2",
    "10 / 2",
    "5 * 4",
    "( 12 + 5 ) * 2",
    "( 15 + 5 ) / 2",
    "12.5 + 5.5"
};

/*
Creating various outputs as test cases to match the above inputs
*/
char *outputs[] = {
    "66\n",
    "8\n",
    "5\n",
    "20\n",
    "34\n",
    "10\n",
    "18\n"
};

/*
This function creates the input from above, and writes it to
input.txt simulating the calculator input
*/
void _create_input(int test_num){
    createTextFile("input.txt", inputs[test_num]);
}

/*
This function allows us to check the value in the output file
and ensures that it is the correct result of the equation
*/
void output_matches_input(int test_num){
    ok(compareTextInFile("log.txt", outputs[test_num]) == 1, "TEST %d", test_num);
}
/*
This is the main function, and iterates through the various test cases
It also runs the calculator in order of:
tokenizer, infixtopostfix, code generator, virtual machine
and then compares the result to ensure its the correct result according
to the input
*/
void testSystemTest(){
    for(int i = 0; i < num_tests; i++){
        _create_input(i);
        startTokenizer();
        startInfixToPostfix();
        printf("Ran i2p\n");
        startCodeGenerator();
        printf("Ran cg\n");
        FILE *saved = stdout;
        stdout = fopen("log.txt", "w");
        startVirtualMachine();
        fclose(stdout);
        stdout = saved;
        output_matches_input(i);
        remove("log.txt");
    }
}

/*
Running the above tests
*/
TESTS {
    testSystemTest();
}
