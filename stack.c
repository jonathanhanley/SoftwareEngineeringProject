//
// Created by Karol Przestrzelski
//

#include <stdlib.h>
#include "stack.h"

// Create new float stack
fstack *FStack(){
    fstack *s = (fstack *)malloc(sizeof(fstack));
    s->list[s->size];
    s->currentPosition = -1;
    return s;
}

// Pop first element off FStack
// If the stack is empty, return 0
float pop(fstack *f){
    if (f->currentPosition == -1)
        return 0;
    float v = f->list[f->currentPosition--];
    return v;
}

// Push new item onto stack
void push(fstack *f, float item){
    f->list[++f->currentPosition] = item;
}

// Get length of stack
int len(fstack *f){
    return f->currentPosition;
}