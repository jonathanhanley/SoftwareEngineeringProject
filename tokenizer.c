//
// Created by Jonathan hanley on 09/10/2019.
//

#include <stdio.h>
#include<string.h>
#include <ctype.h> 
#define OUTPUT_FILE "tokenized.txt"
#define NOMAIN


//Struct to represent a Float, Int or an Opperator
struct Output_type{
    int pointer;
    char type;
    char content[25];
};


//Function to reset the output file back to an empty file
void rest_output_files(){
    FILE *output;
    output = fopen(OUTPUT_FILE, "w");
    fclose(output);
}


//Function to reset the Output_type struct back to default
struct Output_type reset_struct(struct Output_type outputType){
    for (int i = 0; i < outputType.pointer; i++){
        outputType.content[i] = '\0';
    }
    outputType.type = 'I';
    outputType.pointer = 0;

    return outputType;
}


//Function to write an Output_type object to the OUTPUT file
struct Output_type write_item_to_file(struct Output_type outputType){
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
    return reset_struct(outputType);
}

struct Output_type char_to_object(struct Output_type outputType, char character){
        if (isdigit(character) || character == '.'){
            outputType.content[outputType.pointer] = character;
            outputType.pointer ++;

            if (character == '.'){
                outputType.type = 'F';
            }

        } else{

            if (outputType.pointer > 0){
                outputType.content[outputType.pointer] = '\0';
                outputType = write_item_to_file(outputType);
            }

            else if(character == '*' ||
                        character == '-' ||
                        character == '+' ||
                        character == '/'){
                outputType.content[0] = (char) character;
                outputType.type = 'O';
                outputType = write_item_to_file(outputType);
                
            }

            else if(character == '('){
                outputType.content[0] = (char) character;
                outputType.type = 'L';
                outputType = write_item_to_file(outputType);
               
            }

            else if(character == ')'){
                outputType.content[0] = (char) character;
                outputType.type = 'R';
                outputType = write_item_to_file(outputType);
                
            }
        }
    return outputType;
}
//main function
int startTokenizer(){
    rest_output_files();
    char singleLine[150];
    char character;
    FILE *fPointer;
    fPointer = fopen("input.txt", "r");
    fgets(singleLine, 150, fPointer);
    int len = strlen(singleLine);

    //Create the output object
    struct Output_type outputType;
    outputType.pointer = 0;
    outputType.type = 'I';

    //Traverse though the line
    for (int index = 0; index <= len; index++) {

        //Read the character at the position [index]
        character = singleLine[index];
        outputType = char_to_object(outputType, character);


    }
    return 0;
}


#ifdef NOMAIN
int main(){
    return startTokenizer();
}
#endif
