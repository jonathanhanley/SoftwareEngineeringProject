/*
CS3500 - Software Engineering Project

include_files/common.h

Colin Kelleher
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
*/

#ifndef __COMMONCODE__
#define __COMMONCODE__

#include <stdio.h>

/*
Create a structure to hold the inputted characters
(Float, Int, Operator, Bracket) from the file and store them in a struct
*/
typedef struct _CharacterType {
    int pointer;
    int type;
    char content[50];
} CharacterType;


CharacterType *newCharacterType();
void resetCharacterType(CharacterType *charType);
void resultToFile(FILE *outputFile, CharacterType *charType, char * keys[]);
void createTextFile(char *nameOfTextFile, char *content)

#endif
