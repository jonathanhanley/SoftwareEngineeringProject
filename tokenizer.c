//
// Created by Jonathan hanley on 09/10/2019.
//

#include <stdio.h>
#include<string.h>
#include <ctype.h>
#define OUTPUT_FILE "tokenized.txt"
#define NONAME_

//Struct to represent a Float, Int or an Opperator
struct Output_type{
    /*
    pointer attribute keeps track of where the
    next available position is in the character array, content
    */
    int pointer;

    //type attribute is used to store the type of the output
    int type;

    //content attribute is used to store the content of the output
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
        outputType.content[i] = ' ';
    }
    outputType.type = 1;
    outputType.pointer = 0;

    return outputType;
}


//Function that takes integer input and returns the corrosponding Char key
char * int_to_key(int key){
    if (key == 0){
        return "F";
    } else if (key == 1){
        return "I";

    } else if (key == 2){
        return "O";

    } else if (key == 3){
        return "L";

    } else if (key == 4){
        return "R";

    }

    return "Not Valid";

}

//Function to write an Output_type object to the OUTPUT file
void write_item_to_file(struct Output_type outputType){
    FILE *output;
    output = fopen(OUTPUT_FILE, "a");
    int type = outputType.type;
    char* key = int_to_key(type);
    if (type == 3 || type == 4){
        fprintf(output, "%s %c\n", key, outputType.content[0]);
        //printf("%s %c\n", key, outputType.content[0]);

    } else {
        //printf("%s %s\n", key, outputType.content);
        fprintf(output, "%s %s\n", key, outputType.content);
    }

    fclose(output); 
}

//main function
int startTokenizer(){
    //reset the OUTPUT_FILE file
    rest_output_files();

    //Open file and read the first line
    char singleLine[150];
    char character;
    FILE *fPointer;
    fPointer = fopen("input.txt", "r");
    fgets(singleLine, 150, fPointer);
    int len = strlen(singleLine);

    //Create the output object
    struct Output_type outputType;
    outputType.pointer = 0;
    outputType.type = 1;

    //Traverse though the line
    for (int index = 0; index <= len; index++) {

        //Read the character at the position [index]
        character = singleLine[index];

        //Test if the character is a digit or it is a decimail point
        if (isdigit(character) || character == '.'){

            //Add the character to the Output_type content
            outputType.content[outputType.pointer] = character;
            outputType.pointer ++;

            if (character == '.'){
                //If the character is a decimail point change the Output_type type to 0, representing a float
                outputType.type = 0;
            }

        } else{
            //If we have reached the end of the Integer / Float
            if (outputType.pointer > 0){
                //Write the Output_type to file 
                outputType.content[outputType.pointer] = '\0';
                write_item_to_file(outputType);

                //Reset outputType
                outputType = reset_struct(outputType);
            }
        }
        //If the character is an operator
        if(character == '*' ||
                    character == '-' ||
                    character == '+' ||
                    character == '/'){
            outputType.content[0] = (char) character;
            outputType.type = 2;
            write_item_to_file(outputType);
            outputType = reset_struct(outputType);
        }

        else if(character == '('){
            outputType.content[0] = (char) character;
            outputType.type = 3;
            write_item_to_file(outputType);
            outputType = reset_struct(outputType);
        }

        else if(character == ')'){
            outputType.content[0] = (char) character;
            outputType.type = 4;
            write_item_to_file(outputType);
            outputType = reset_struct(outputType);
        }
        


    }
    return 0;
}


#ifdef NOMAIN
int main(){
    return startTokenizer();
}
#endif
