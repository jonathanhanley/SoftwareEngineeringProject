/*
CS3500 - Software Engineering Project

include_files/virtualmachine.h

Colin Kelleher
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
*/

#ifndef __VIRTUALMACHINE__
#define __VIRTUALMACHINE__

#include "stack.h"

int startVirtualMachine();
// Struct for each instruction holding the operation and value
typedef struct __instruction {
    char op[10];
    char value[];
} instruction;
/*
 Split *line into op and value - seperated by space
 And return new *instruction
*/
instruction *parse_instruction(char *line);
/*
Check which instruction was read annd apply it on the stack
*/
void execute(instruction *i, fstack *f);

#endif
