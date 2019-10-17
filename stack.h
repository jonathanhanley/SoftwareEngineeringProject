//
// Created by Karol Przestrzelski
//

// Defines the float stack methods and struct
#ifndef __fstack__
#define __fstack__

typedef struct __fstack {
    int currentPosition;
    long size: 64;
    float list[];
} fstack;

fstack *FStack();
float pop(fstack *f);
void push(fstack *f, float item);
int len(fstack *f);

#endif
