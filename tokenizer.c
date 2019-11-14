/*
CS3500 - Software Engineering Project

Created by Jonathan Hanley

Contributed to by:
Karol Przestrzelski
Colin Kelleher
Liam de la Cour
*/

/*
 include statements & defining output file
*/
#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include "common.h"
#define OUTPUT_FILE "tokenized.txt"
#define NOMAIN_

/*
Function to reset the output file back to an empty file
*/
void rest_output_files(){
    FILE *output;
    output = fopen(OUTPUT_FILE, "w");
    fclose(output);
}

/*
Adding the appropriate token to the corresponding
input from the file
for example 'O' is assigned to all operators [-,+,/]
and is then written out
*/

char *keys[] = {"F", "I", "O", "L", "R"};
void convert_char_2_object(CharacterType *outputType, char character){
        FILE *output;
        output = fopen(OUTPUT_FILE, "a");
        if (isdigit(character) || character == '.'){
            outputType->content[outputType->pointer] = character;
            outputType->pointer ++;
            if (character == '.'){
                outputType->type = 0;
            }

        }

        else if (outputType->pointer > 0){
                outputType->content[outputType->pointer] = '\0';
                resultToFile(output, outputType, keys);
        }

        if(character == '*' ||
                    character == '-' ||
                    character == '+' ||
                    character == '/'){
            outputType->content[outputType->pointer++] = (char) character;
            outputType->type = 2;
            resultToFile(output, outputType, keys);
        }

        else if(character == '('){
            outputType->content[outputType->pointer++] = (char) character;
            outputType->type = 3;
            resultToFile(output, outputType, keys);
        }

        else if(character == ')'){
            outputType->content[outputType->pointer++] = (char) character;
            outputType->type = 4;
            resultToFile(output, outputType, keys);
        }
        fclose(output);
}
/*
main function
Used for running the tokenizer
File Handling & Dealing with strctures
*/
int startTokenizer(){
    rest_output_files();

    char singleLine[150];
    char character;
    FILE *fPointer;
    fPointer = fopen("input.txt", "r");
    fgets(singleLine, 150, fPointer);
    int len = strlen(singleLine);

    CharacterType *outputType = newCharacterType();

    for (int index = 0; index <= len; index++) {

        character = singleLine[index];
        convert_char_2_object(outputType, character);


    }
    return 0;
}

/*
Used for testing
*/
#ifdef NOMAIN
int main(){
    return startTokenizer();
}
#endif
