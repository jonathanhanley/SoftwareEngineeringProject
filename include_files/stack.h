/*
CS3500 - Software Engineering Project

include_files/stack.h

Colin Kelleher
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
*/

// Defines the float stack methods and struct
#ifndef __fstack__
#define __fstack__

#define STACK_SIZE 64

typedef struct __fstack {
    int currentPosition;
    long size: STACK_SIZE;
    float list[];
} fstack;

fstack *FStack();
float pop(fstack *f);
void push(fstack *f, float item);
int len(fstack *f);

#endif
