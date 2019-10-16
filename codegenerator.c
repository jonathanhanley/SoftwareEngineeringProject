/*
CS3500 - Software Engineering Project
Calculator using - Tokenizer, infix2postfix, code generator, VM

codegenerator.c
Created by Colin Kelleher
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
Create a structure to hold the inputted characters 
(Float, Int, Operator) from the file and store them in a struct
*/
struct InputtedType {
    int pointer;
    int type;
    char content[50];
};

 /*
Below is a function used to reset the above struct
back to its original values, to perform the next task.
These values can also be seen within the main, when creating. 
This function is vital to reset the structure after use, to ensure
correctness. 
*/
struct InputtedType reset_struct (struct InputtedType inputtedtype){
    for (int i = 0; i < inputtedtype.pointer; i++) {
        inputtedtype.content[i] = ' ';
    }
    inputtedtype.type = 1;
    inputtedtype.pointer = 0;
    return inputtedtype;
}
 /*
The keyToValue function below, takes a key, assigned to an INT, FLOAT
or OPERATOR, and translates it to the appropriate INSTRUCTION as specified
in the INSTRUCTION SET
I.E.: All floats are assigned to key 0 in the main, which is then translated 
to the 'floatinstr' here which contrains the correction instruction LOADFLOAT
*/
char * keyToValue (int key) {
    // Keys are assigned within the 'main'
    if (key == 0) 
    {
        // floatinstr and corresponding below are all defined at the start
        // using 'define' statements
        return floatinstr;
    } else if (key == 1)
    {
        return intinstr;
    } else if (key == 2)
    {
        return multiplyinstr;
    } else if (key == 3)
    {
        return divideinstr;
    } else if (key == 4)
    {
        return addinstr;
    } else if (key == 5)
    {
        return subtractinstr;
    } else
    {
        return "Not Valid - TRY AGAIN!";
    }
};

/*
This is the function I call to write the result to the file
I open the file in "a" = append mode, to append each instruction on to the end of the file.
If I open the file in "w" = write mode, only the last instruction will be written
to the file.
strcmp = string compare.
The instriction is then written to the outputfile according to the formatting
i have specified in the code (i.e.: one instruction per line)
*/
void resultToFile( struct InputtedType inputtedtype) {
    FILE *outputFile;
    outputFile = fopen(_outputFile_, "a");
    int type = inputtedtype.type;
    char *key = keyToValue(type);
    if (strcmp(key,floatinstr) || strcmp(key, intinstr)) {
        fprintf(outputFile, "%s %s\n", key, inputtedtype.content);
    }else
    {
        fprintf(outputFile, "%s %c\n", key, inputtedtype.content[0]);
    }
    fclose(outputFile);
};

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
int main () {
    // 1)
    FILE *outputFile;
    outputFile = fopen(_outputFile_, "w");
    fclose(outputFile);

    // 2
    struct InputtedType inputtedtype ;
    inputtedtype.pointer = 0;
    inputtedtype.type = 1;

    // 3
    char lineread[100];
    char character;
    FILE * inputFile;
    inputFile = fopen(_inputFile_, "r");
    //    fgets(pointer to array of chars, max num of chars to be read, file pointer)
    fgets(lineread,100,inputFile);

    // 4
    for (int index = 0; index < strlen(lineread); index ++) {
        character = lineread[index];

        // || - if isdigit(character) OR character == '.' is true
        // If one of them is true run the code following
        if (isdigit(character) || character == '.'){
            inputtedtype.content[inputtedtype.pointer] = character;
            inputtedtype.pointer ++;
            // if there is a '.' it is assigned a type of 0, corresponding to a float
            if (character == '.'){
                inputtedtype.type = 0;
            }
            } else {
                if (inputtedtype.pointer > 0) {
                    resultToFile(inputtedtype);
                    inputtedtype = reset_struct(inputtedtype);
                }
            }
            // If the character ='*' meaning multiplication, type 2 is assigned
            if (character == '*') 
            {
                inputtedtype.type = 2;
                resultToFile(inputtedtype);
            } else if (character == '/')
            {
                inputtedtype.type = 3;
                resultToFile(inputtedtype);
            } else if (character == '+')
            {
                inputtedtype.type = 4;
                resultToFile(inputtedtype);
            } else if (character == '-') {
                inputtedtype.type = 5;
                resultToFile(inputtedtype);
            }
            // Output file is then closed. 
            fclose(outputFile);                   
        }
    }
/*
Sample Input:

1.33 24.6 366 * + / - 

Sample Output:

LOADFLOAT 1.33
LOADFLOAT 24.6
LOADINT 366
MUL
ADD
DIV
SUB
*/