/*
CS3500 - Software Engineering Project

Created by Jonathan Hanley

Contributed to by: 
Colin Kelleher
Karol Przestrzelski
Liam de la Cour
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "common.h"

#define OUTPUT_FILE "tokenized.txt"
#define NONAME_

 /*
The string array that holds the corresponding keys associated with each integer value 
Assigned in startTokenizer
*/
char * tokenKeys[] = {"F", "I", "O", "L", "R"};

/*
Main function
*/
int startTokenizer(){
    // Reset the OUTPUT_FILE file
    FILE *outputFile;
    outputFile = fopen(OUTPUT_FILE, "w");

    // Open file and read the first line
    char singleLine[150];
    char character;
    FILE *fPointer;
    fPointer = fopen("input.txt", "r");
    fgets(singleLine, 150, fPointer);
    int len = strlen(singleLine);

    // Create the output object
    CharacterType *charType = newCharacterType();

    // Traverse though the line
    for (int index = 0; index <= len; index++) {

        // Read the character at the position [index]
        character = singleLine[index];

        // Test if the character is a digit or it is a decimail point
        if (isdigit(character) || character == '.'){

            // Add the character to the Output_type content
            charType->content[charType->pointer] = character;
            charType->pointer ++;

            if (character == '.'){
                // If the character is a decimail point change the Output_type type to 0, representing a float
                charType->type = 0;
            }
        } else {
            if (charType->pointer > 0){
                // Write the Output_type to file 
                resultToFile(outputFile, charType, tokenKeys);
            }
        }
        // If the character is an operator
        if(character == '*' ||
                    character == '-' ||
                    character == '+' ||
                    character == '/'){
            charType->content[charType->pointer++] = (char) character;
            charType->type = 2;
        }

        else if(character == '('){
            charType->content[charType->pointer++] = (char) character;
            charType->type = 3;
        }

        else if(character == ')'){
            charType->content[charType->pointer++] = (char) character;
            charType->type = 4;
        }
        // If have read a character that wasn't a space or number, write it
        if (charType->type > 1){
            // Write the Output_type to file 
            resultToFile(outputFile, charType, tokenKeys);
        }
    }
    fclose(outputFile);

    return 0;
}


#ifdef NOMAIN
int main(){
    return startTokenizer();
}
#endif
