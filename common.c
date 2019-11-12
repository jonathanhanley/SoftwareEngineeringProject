/*
CS3500 - Software Engineering Project

Created by Colin Kelleher

Contributed to by: 
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour

Common C functions and structs that are used throughout different components

*/

/*
Include & Define statement block
<stdio.h> is useful for dealing with inputs and outputs
<string.h> is useful for dealing with strings & arrays of characters
<ctype.h> is useful for testing and mapping characters / character handling
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "common.h"


/*
Allocate memory for a new CharacterType 
Set its default values using the reset function
and return its pointer
*/
CharacterType *newCharacterType(){
    CharacterType *charType = (CharacterType *)malloc(sizeof(CharacterType));
    resetCharacterType(charType);
    return charType;
}

 /*
Below is a function used to reset the above struct
back to its original values, to perform the next task.
These values can also be seen within the main, when creating. 
This function is vital to reset the structure after use, to ensure
correctness. 
*/
void resetCharacterType (CharacterType *charType){
    charType->type = 1;
    charType->pointer = 0;
}

/*
This is the function I call to write the result to the file
The getKey function is component specific and should be passed through like &keyToValue
The instriction is then written to the outputfile according to the formatting
i have specified in the code (i.e.: one instruction per line)
*/
void resultToFile(FILE *outputFile, CharacterType *charType, char * keys[]) {
    int type = charType->type;
    char *key = keys[type];
    charType->content[charType->pointer] = '\0';
    fprintf(outputFile, "%s %s\n", key, charType->content);
    resetCharacterType(charType);
};