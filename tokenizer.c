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
#define OUTPUT_FILE "tokenized.txt"
#define NOMAIN_

struct Output_type{
    int pointer;
    char type;
    char content[25];
};

/*
Function to reset the output file back to an empty file
*/
void rest_output_files(){
    FILE *output;
    output = fopen(OUTPUT_FILE, "w");
    fclose(output);
}
/*
Function to reset the Output_type struct back to default
*/
struct Output_type reset_struct(struct Output_type outputType){
    for (int i = 0; i < outputType.pointer; i++){
        outputType.content[i] = '\0';
    }
    outputType.type = 'I';
    outputType.pointer = 0;

    return outputType;
}
/*
Function to write an Output_type object to the OUTPUT file
*/
void write_item_to_file(struct Output_type outputType){
    FILE *output;
    output = fopen(OUTPUT_FILE, "a");
    char type = outputType.type;
    if (type == ')' || type == '('){
        fprintf(output, "%c %c\n", type, outputType.content[0]);
        printf("%c %c\n", type, outputType.content[0]);

    } else {
        printf("%c %s\n", type, outputType.content);
        fprintf(output, "%c %s\n", type, outputType.content);
    }


    fclose(output); 
}
/*
Adding the appropriate token to the corresponding 
input from the file 
for example 'O' is assigned to all operators [-,+,/]
and is then written out
*/
struct Output_type convert_char_2_object(struct Output_type outputType, char character){
        if (isdigit(character) || character == '.'){
            outputType.content[outputType.pointer] = character;
            outputType.pointer ++;
            if (character == '.'){
                outputType.type = 'F';
            }

        } else{
            if (outputType.pointer > 0){
                outputType.content[outputType.pointer] = '\0';
                write_item_to_file(outputType);
                outputType = reset_struct(outputType);
            }
        }
        if(character == '*' ||
                    character == '-' ||
                    character == '+' ||
                    character == '/'){
            outputType.content[0] = (char) character;
            outputType.type = 'O';
            write_item_to_file(outputType);
            outputType = reset_struct(outputType);
        }

        else if(character == '('){
            outputType.content[0] = (char) character;
            outputType.type = 'L';
            write_item_to_file(outputType);
            outputType = reset_struct(outputType);
        }

        else if(character == ')'){
            outputType.content[0] = (char) character;
            outputType.type = 'R';
            write_item_to_file(outputType);
            outputType = reset_struct(outputType);
        }
    
    return outputType;
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

    struct Output_type outputType;
    outputType.pointer = 0;
    outputType.type = 1;

    for (int index = 0; index <= len; index++) {

        character = singleLine[index];
        outputType = convert_char_2_object(outputType, character);


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
