//
// Created by Karol Przestrzelski
//

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
