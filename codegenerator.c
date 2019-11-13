/*
CS3500 - Software Engineering Project

Created by Colin Kelleher

Contributed to by:
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
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
#include "codegenerator.h"
/*
defining the input & output files - ease of maintenance and
only have to change in one place should these files need to be
renamed
*/
#define _inputFile_ "postfixed.txt"
#define _outputFile_ "codegenerated.txt"
/*
INSTRUCTION SET
ease of maintenance and only have to change in one place
should these insructions need to be given new values/ new instruction
set.
*/
#define floatinstr "LOADFLOAT"
#define intinstr "LOADINT"
#define multiplyinstr "MUL"
#define divideinstr "DIV"
#define addinstr "ADD"
#define subtractinstr "SUB"

 /*
The string array that holds the corresponding keys associated with each integer value
Assigned in startCodeGenerator
*/
char * instructionKeys[] = {floatinstr, intinstr, multiplyinstr, divideinstr, addinstr, subtractinstr};

char *readLine(){
    // 3
    char lineread[100];
    FILE * inputFile;
    inputFile = fopen(_inputFile_, "r");
    //    fgets(pointer to array of chars, max num of chars to be read, file pointer)
    fgets(lineread,100,inputFile);
    fclose(inputFile);
    return lineread;
}

void classifyChar(CharacterType *charType, char character){
    // || - if isdigit(character) OR character == '.' is true
    // If one of them is true run the code following
    if (isdigit(character) || character == '.'){
        charType->content[charType->pointer] = character;
        charType->pointer ++;
        // if there is a '.' it is assigned a type of 0, corresponding to a float
        if (character == '.'){
            charType->type = 0;
        }
    }
    // If the character ='*' meaning multiplication, type 2 is assigned
    else if (character == '*') {
        charType->type = 2;
    } else if (character == '/') {
        charType->type = 3;
    } else if (character == '+') {
        charType->type = 4;
    } else if (character == '-') {
        charType->type = 5;
    }
}
 /*
This is the 'main' function where the code is ran from.
1) I open & close the output file to reset it back to an original blank file (this
   is to ensure that the file is clear of the previous calculation)
2) I am creating the struct object to be used for Int, Float & Operators
   and store them in this struct
3) I am openeing the input file in "r" = read mode. I am reading the line from the
   input file. I only read a line as this is all that is required, as everything should
   always be on a single line following infix2postfix and according to the documentation
   The inputted string is stored in lineread
4) I am checking the type of the inputter characters(numbers/operators)Here.
   If they contrain a '.' they are assigned a type of 0 which means it is a float,
   1 if it is an Integer.....and so on... resultToFile is then called to write
   the Instruction to the file
   The output file is then closed
*/
int startCodeGenerator () {
    // 1)
    FILE *outputFile;
    outputFile = fopen(_outputFile_, "w");

    // 2
    CharacterType *charType = newCharacterType();

    // 3
    char *lineread = readLine();
    char character;

    // 4
    for (int index = 0; index < strlen(lineread); index ++) {
        character = lineread[index];
        // Infix to postfix has a space seperating each part so write on that
        // Set the key (instruction) first
        if (character == ' ')
            resultToFile(outputFile, charType, instructionKeys);
        else
            classifyChar(charType, character);
    }
    fclose(outputFile);
 return 0;
}

#ifdef NOMAIN
int main(){
    return startCodeGenerator();
}
#endif

/*
Sample Input:

1.33 24.6 366 * + / -

Sample Output:

LOADFLOAT 1.33
LOADFLOAT 24.6
LOADINT 366
MUL
ADD
DIV
SUB
*/
