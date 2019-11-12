//
// Created by Jonathan hanley on 09/10/2019.
//

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
//main function
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


#ifdef NOMAIN
int main(){
    return startTokenizer();
}
#endif
