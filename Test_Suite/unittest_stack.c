/*
CS3500 - Software Engineering Project


UNIT TEST - Stack

Colin Kelleher
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
*/

/*
Include statements
*/
#include "stack.h"
#include <stdio.h>
#include <ctap.h>

/*
A test to check if the stack is empty
Returns OK is length of stack is zero
*/
void testEmptyStack(){
    fstack *stack = FStack();
    ok(len(stack) == 0, "Length of new stack is 0");
}

/*
Checking stack operations 
Push, Pop, Size
*/
void testOperations(){
    fstack *stack = FStack();
    // Push 3 elements onto stack
    for (int i=0; i<3; i++){
        push(stack, i);
        char *baseMsg = "Pushing worked for: %f";
        char msg[50];
        sprintf(msg, baseMsg, stack->list[stack->currentPosition]);
        ok(stack->list[stack->currentPosition] == (float)i, msg);
        printf("hi\n");
    }
    ok(len(stack) == 3, "Stack size is 3");
    // Remove elements validating whether they're right
    for (int i=2; i>-1; i--){
        float v = pop(stack);
        char *baseMsg = "Popping worked for: %d";
        char msg[50];
        sprintf(msg, baseMsg, i);
        ok((float)i == v, msg);
    }
    ok(len(stack) == 0, "Stack is empty again");
}

/*
Running the above tests
*/
TESTS{
    testEmptyStack();
    testOperations();
}
