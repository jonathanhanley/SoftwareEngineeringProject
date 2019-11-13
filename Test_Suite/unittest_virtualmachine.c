#include <ctap.h>
#include "virtualmachine.h"
#include "stack.h"

void testInstructionParse(){
    // All instructions to be tested
    instruction *i;
    char *loadInt = "LOADINT 123";
    i = parse_instruction(loadInt, 12);
    is(i->op, "LOADINT", "LOADINT operation parsed successfully");
    is(i->value, "123", "LOADINT value parsed successfully");

    char *loadFloat = "LOADFLOAT 1.23";
    i = parse_instruction(loadFloat, 13);
    is(i->op, "LOADFLOAT", "LOADFloat operation parsed successfully");
    is(i->value, "1.23", "LOADFLOAT value parsed successfully");

    char *add = "ADD";
    i = parse_instruction(add, 4);
    is(i->op, "ADD", "ADD operation recognised successfully");

    char *sub = "SUB";
    i = parse_instruction(sub, 4);
    is(i->op, "SUB", "SUB operation recognised successfully");

    char *mul = "MUL";
    i = parse_instruction(mul, 4);
    is(i->op, "MUL", "MUL operation recognised successfully");

    char *div = "DIV";
    i = parse_instruction(div, 4);
    is(i->op, "DIV", "DIV operation recognised successfully");
}

void testExecuteInstruction(){
    // Test adding two numbers together
    fstack *stack = FStack();
    instruction *i;
    i = parse_instruction("LOADINT 12", 11);
    execute(i, stack);
    i = parse_instruction("LOADINT 12", 11);
    execute(i, stack);
    i = parse_instruction("ADD", 4);
    execute(i, stack);
    ok(pop(stack) == (float)24, "Doing 12 + 12 worked");
    free(i);
    ok(len(stack) == 0, "Operation has left stack empty");

    // Test subtracting a numbers
    i = parse_instruction("LOADINT 12", 11);
    execute(i, stack);
    i = parse_instruction("LOADINT 6", 11);
    execute(i, stack);
    i = parse_instruction("SUB", 4);
    execute(i, stack);
    ok(pop(stack) == (float)6, "Doing 12 - 6 worked");
    free(i);
    ok(len(stack) == 0, "Operation has left stack empty");

    // Test dividing a number
    i = parse_instruction("LOADINT 12", 11);
    execute(i, stack);
    i = parse_instruction("LOADINT 3", 11);
    execute(i, stack);
    i = parse_instruction("DIV", 4);
    execute(i, stack);
    ok(pop(stack) == (float)4, "Doing 12 / 3 worked");
    free(i);
    ok(len(stack) == 0, "Operation has left stack empty");

    // Test multiplying a number
    i = parse_instruction("LOADINT 4", 11);
    execute(i, stack);
    i = parse_instruction("LOADINT 3", 11);
    execute(i, stack);
    i = parse_instruction("MUL", 4);
    execute(i, stack);
    ok(pop(stack) == (float)12, "Doing 3 * 4 worked");
    free(i);
    ok(len(stack) == 0, "Operation has left stack empty");
}

void testRunVirtualMachine(){

}

TESTS {
    testInstructionParse();
    testExecuteInstruction();
    testRunVirtualMachine();
}
