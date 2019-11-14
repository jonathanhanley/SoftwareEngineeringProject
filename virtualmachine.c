/*
CS3500 - Software Engineering Project

Created by Karol Przestrzelski

Contributed to by:
Jonathan Hanley
Colin Kelleher
Liam de la Cour
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Include float stack
#include "virtualmachine.h"
#include "stack.h"

#define INPUT_FILE "codegenerated.txt"
// Check if two strings are equal
#define EQUAL(a,b) strcmp((a), (b)) == 0
// Check if a is equal to instructions
#define LOADINT(a) EQUAL((a), "LOADINT")
#define LOADFLOAT(a) EQUAL((a), "LOADFLOAT")
#define ADD(a) EQUAL((a), "ADD")
#define SUB(a) EQUAL((a), "SUB")
#define MUL(a) EQUAL((a), "MUL")
#define DIV(a) EQUAL((a), "DIV")
/*
 Do the 'o' operator on the top two elements of f (the float stack)
 Push the result back onto f
*/
#define OP(o)   float two = pop(f); \
                float one = pop(f); \
                push(f, one o two); \

/*
 Split *line into op and value - seperated by space
 And return new *instruction
*/
instruction *parse_instruction(char *line){
    // Allocate space in memory for instruction
    instruction *ins = (instruction *)malloc(sizeof(instruction));
    size_t length = strlen(line);
    // Set the value array length
    ins->value[length];
     // Iterate through each character in the line until newline
     // or space is reached or if the length of the line is reached
    char *ptr = line;
    int i = 0;
    while (i < length && *ptr != ' ' && *ptr != '\n'){
        ins->op[i++] = *ptr;
        ptr++;
    }
    // Add null character to make it a string
    ins->op[i] = '\0';
    // Keep iterating through the line to get the values
    i = 0;
    while (*ptr != '\0' ){
        if (*ptr == ' ') ptr++;
        ins->value[i++] = *ptr;
        ptr++;
    }
    ins->value[i] = '\0';
    return ins;
}

/*
Check which instruction was read annd apply it on the stack
*/
void execute(instruction *i, fstack *f){
    if (LOADINT(i->op)){
        push(f, atof(i->value));
    } else if (LOADFLOAT(i->op)){
        push(f, atof(i->value));
    } else if (ADD(i->op)){
        OP(+);
    } else if (SUB(i->op)){
        OP(-);
    }else if (MUL(i->op)){
        OP(*);
    }else if (DIV(i->op)){
        OP(/);
    }
    // Free instruction after using it
    free(i);
}

void processFile(FILE *fp, fstack *stack){
  char *line = NULL;
  ssize_t len = 0;
  ssize_t read;
  // Read each line
  while ((read = getline(&line, &len, fp)) != -1) {
      // Get new instruction passing in the line array and the length of the line
      instruction *i = parse_instruction(line);
      // Run the instruction on the line
      execute(i, stack);
  }
  // Close the file
  fclose(fp);
}

/*
Read the INPUT_FILE line by line, executing each instruction line
Print the output of stack
*/
int startVirtualMachine(){
    // Initialize variables for reading the file
    FILE *fp = fopen(INPUT_FILE, "r");
    // Create float stack of length 16
    fstack *stack = FStack();
    // Process the file line by line
    processFile(fp, stack);
    // Print the last item from the stack
    printf("%.6g\n", pop(stack));

    free(stack);
}

#ifdef NOMAIN
int main(){
    return startVirtualMachine();
}
#endif
