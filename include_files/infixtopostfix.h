/*
CS3500 - Software Engineering Project

include_files/infixtopostfix.h

Colin Kelleher
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
*/

#ifndef __INFIXTOPOSTIX__
#define __INFIXTOPOSTIX__
#include <stdbool.h>

int startInfixToPostfix();
bool greaterPrecedence(char op1, char op2);
bool equalPrecedence(char op1, char op2);

#endif
