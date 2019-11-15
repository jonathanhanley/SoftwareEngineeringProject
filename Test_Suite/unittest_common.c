/*
CS3500 - Software Engineering Project


UNIT TEST - Common

Colin Kelleher
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
*/


/*
Include statements
*/
#include <ctap.h>
#include "common.h"

/*
Testing resetting the structure
Creating test cases - list of inputs
checking setting/resetting output_type->content
checking setting/resetting  output_type->type
checking setting/resetting  output_type->pointer
*/
void test_reset_struct(){
        CharacterType *output_type = newCharacterType();
        char inputs[] = {'L', 'R', ')', '(', 'O'};
        for (int i = 0; i < 5; i++){
            output_type->type = i;
            output_type->content[0] = inputs[i];
            output_type->pointer = 1;
            ok(strlen(output_type->content) > 0, "output_type->content has set");
            ok(output_type->type == i, "output_type->type has been set");
            ok(output_type->pointer != 0, "output_type->pointer has been increased");
            resetCharacterType(output_type);
            ok(strlen(output_type->content) == 0, "output_type->content has been reset");
            ok(output_type->type == 1, "output_type->type has been reset");
            ok(output_type->pointer == 0, "output_type->pointer has been reset");

        }
}

/*
Testing writing an Output_type struct to a file
Writes several structs to the file
Checks the file to see if the structs have been written to the
file correctly
*/
void test_write_item_to_file(){
    CharacterType *output_type = newCharacterType();
    FILE *outFile;
    outFile = fopen("tokenized.txt", "w");
    char *keys[] = {"F", "I", "O", "L", "R"};
    output_type->type = 1;
    output_type->content[0] = '1';
    output_type->pointer = 1;
    output_type->content[1] = '0';
    output_type->pointer++;
    resultToFile(outFile, output_type, keys);
    resetCharacterType(output_type);

    output_type->type = 2;
    output_type->content[0] = '+';
    output_type->pointer++;
    resultToFile(outFile, output_type, keys);
    resetCharacterType(output_type);

    output_type->type = 3;
    output_type->content[0] = '(';
    output_type->pointer++;
    resultToFile(outFile, output_type, keys);
    resetCharacterType(output_type);

    output_type->type = 4;
    output_type->content[0] = ')';
    output_type->pointer++;
    resultToFile(outFile, output_type, keys);
    resetCharacterType(output_type);

    fclose(outFile);

    FILE * file;
    char * line;
    size_t length = 0;
    ssize_t read;
    file = fopen("tokenized.txt", "r");
    read = getline(&line, &length, file);
    is_string(line , "I 10\n", "First Line Okay");
    read = getline(&line, &length, file);
    is_string(line, "O +\n", "Second Line Okay");
    read = getline(&line, &length, file);
    is_string(line, "L (\n", "Third Line Okay");
    read = getline(&line, &length, file);
    is_string(line, "R )\n", "Fourth Line Okay");
    fclose(file);
}
/*
Testing the new character type 
- Pointer
- Type
- Content
*/
void test_new_character_type(){
    CharacterType *char_type = newCharacterType();
    ok(char_type->pointer == 0, "CharacterType pointer initialized okay");
    ok(char_type->type == 1, "CharacterType type initialized okay");
    ok(strlen(char_type->content) == 0, "CharacterType content initialized okay");
}

/*
Running the above tests
*/

TESTS {
    test_new_character_type();
    test_reset_struct();
    test_write_item_to_file();
}
