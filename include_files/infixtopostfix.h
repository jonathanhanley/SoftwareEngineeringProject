//
// Created by Karol Przestrzelski
//

#ifndef __INFIXTOPOSTIX__
#define __INFIXTOPOSTIX__
#include <stdbool.h>

int startInfixToPostfix();
bool greaterPrecedence(char op1, char op2);
bool equalPrecedence(char op1, char op2);

#endif
