/*
CS3500 - Software Engineering Project

include_files/codegenerator.h

Colin Kelleher
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
*/



#ifndef __CODEGENERATOR__
#define __CODEGENERATOR__

#include "common.h"
#include <stdio.h>

int startCodeGenerator();
void classifyChar(CharacterType *charType, char character);
char *readLine();

#endif
