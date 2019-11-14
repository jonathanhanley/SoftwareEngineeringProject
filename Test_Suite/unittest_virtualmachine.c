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

void testInstructionParse(){
    // All instructions to be tested
    instruction *i;
    char *loadInt = "LOADINT 123";
    i = parse_instruction(loadInt);
    is(i->op, "LOADINT", "LOADINT operation parsed successfully");
    is(i->value, "123", "LOADINT value parsed successfully");

    char *loadFloat = "LOADFLOAT 1.23";
    i = parse_instruction(loadFloat);
    is(i->op, "LOADFLOAT", "LOADFloat operation parsed successfully");
    is(i->value, "1.23", "LOADFLOAT value parsed successfully");

    char *add = "ADD";
    i = parse_instruction(add);
    is(i->op, "ADD", "ADD operation recognised successfully");

    char *sub = "SUB";
    i = parse_instruction(sub);
    is(i->op, "SUB", "SUB operation recognised successfully");

    char *mul = "MUL";
    i = parse_instruction(mul);
    is(i->op, "MUL", "MUL operation recognised successfully");

    char *div = "DIV";
    i = parse_instruction(div);
    is(i->op, "DIV", "DIV operation recognised successfully");
}

void testExecuteInstruction(){
    // Test adding two numbers together
    fstack *stack = FStack();
    instruction *i;
    i = parse_instruction("LOADINT 12");
    execute(i, stack);
    i = parse_instruction("LOADINT 12");
    execute(i, stack);
    i = parse_instruction("ADD");
    execute(i, stack);
    ok(pop(stack) == (float)24, "Doing 12 + 12 worked");
    free(i);
    ok(len(stack) == 0, "Operation has left stack empty");

    // Test subtracting a numbers
    i = parse_instruction("LOADINT 12");
    execute(i, stack);
    i = parse_instruction("LOADINT 6");
    execute(i, stack);
    i = parse_instruction("SUB");
    execute(i, stack);
    ok(pop(stack) == (float)6, "Doing 12 - 6 worked");
    free(i);
    ok(len(stack) == 0, "Operation has left stack empty");

    // Test dividing a number
    i = parse_instruction("LOADINT 12");
    execute(i, stack);
    i = parse_instruction("LOADINT 3");
    execute(i, stack);
    i = parse_instruction("DIV");
    execute(i, stack);
    ok(pop(stack) == (float)4, "Doing 12 / 3 worked");
    free(i);
    ok(len(stack) == 0, "Operation has left stack empty");

    // Test multiplying a number
    i = parse_instruction("LOADINT 4");
    execute(i, stack);
    i = parse_instruction("LOADINT 3");
    execute(i, stack);
    i = parse_instruction("MUL");
    execute(i, stack);
    ok(pop(stack) == (float)12, "Doing 3 * 4 worked");
    free(i);
    ok(len(stack) == 0, "Operation has left stack empty");
    free(stack);
}

void testRunVirtualMachine(){
    createTextFile("codegenerated.txt", "LOADINT 4\nLOADINT 4\nADD \nLOADINT 10\nMUL \n");
    FILE *saved = stdout;
    stdout = fopen("log.txt", "w");
    startVirtualMachine();
    fclose(stdout);
    stdout = saved;
    ok(compareTextInFile("log.txt", "80\n") == 1, "Running virtual machine works");
    remove("log.txt");
}
/*
Running the above tests
*/
TESTS {
    testInstructionParse();
    testExecuteInstruction();
    testRunVirtualMachine();
}
