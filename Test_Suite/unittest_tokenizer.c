/*
CS3500 - Software Engineering Project

Testing with Tap

Colin Kelleher
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
*/


/*
Include statements
*/
#include <ctap.h>
#include "../tokenizer.c"


/*
Testing the output file (text file)
Creating test cases - list of inputs [0-9] as below
Checking if the content has been written to the file, checking size
and then resetting the file 
*/
void test_rest_output_files(){
    char *inputs[10];
    inputs[0] = "1+1";
    inputs[1] = "(1+1) * 100";
    inputs[2] = "10 * 1 / 1";
    inputs[3] = "11 *1";
    inputs[4] = "1";
    inputs[5] = "99 / 1 * 10 + 100 - 82 / 2";
    inputs[6] = "0 / 2";
    inputs[7] = "2 * 2 + 6";
    inputs[8] = "0 + 0";
    inputs[9] = "()";

    for (int i = 0; i < 10; i++){
        FILE *testing_text_file;
        testing_text_file = fopen("tokenized.txt", "w");
        fprintf(testing_text_file, "%s", inputs[i]);
        fseek(testing_text_file, 0, SEEK_END); 
        long fsize= ftell(testing_text_file);
        fclose(testing_text_file);
        ok(fsize > 0, "File has content");
        rest_output_files();
        testing_text_file = fopen("tokenized.txt", "a");
        fsize= ftell(testing_text_file);
        ok(fsize == 0, "File has been reset");
        fclose(testing_text_file);
    }
}

/*
Testing resetting the structure
Creating test cases - list of inputs
checking setting/resetting output_type.content
checking setting/resetting  output_type.type
checking setting/resetting  output_type.pointer
*/
void test_reset_struct(){
        struct Output_type output_type;
        char inputs[] = {'L', 'R', ')', '(', 'O'};
        for (int i = 0; i < 5; i++){
            output_type.type = inputs[i];
            output_type.content[0] = inputs[i];
            output_type.pointer = 1;
            ok(strlen(output_type.content) > 0, "output_type.content has set");
            ok(output_type.type == inputs[i], "output_type.type has been set");
            ok(output_type.pointer != 0, "output_type.pointer has been increased");
            output_type = reset_struct(output_type);
            ok(strlen(output_type.content) == 0, "output_type.content has been reset");
            ok(output_type.type == 'I', "output_type.type has been reset");
            ok(output_type.pointer == 0, "output_type.pointer has been reset");

        }
}

void test_write_item_to_file(){
    struct Output_type output_type;
    rest_output_files();
    output_type.type = 'I';
    output_type.content[0] = '1';
    output_type.pointer = 1;
    output_type.content[1] = '0';
    output_type.pointer++;
    write_item_to_file(output_type);
    output_type = reset_struct(output_type);

    output_type.type = 'O';
    output_type.content[0] = '+';
    output_type.pointer++;
    write_item_to_file(output_type);
    output_type = reset_struct(output_type);

    output_type.type = 'L';
    output_type.content[0] = '(';
    output_type.pointer++;
    write_item_to_file(output_type);
    output_type = reset_struct(output_type);

    output_type.type = 'R';
    output_type.content[0] = ')';
    output_type.pointer++;
    write_item_to_file(output_type);
    output_type = reset_struct(output_type);

    FILE * file;
    char * line;
    size_t length = 0;
    ssize_t read;
    file = fopen("tokenized.txt", "r");
    read = getline(&line, &length, file);
    ok(strcmp(("%s", line), "I 10\n") == 0, "First Line Okay");
    read = getline(&line, &length, file);
    ok(strcmp(("%s", line), "O +\n") == 0, "Second Line Okay");
    read = getline(&line, &length, file);
    ok(strcmp(("%s", line), "L (\n") == 0, "Third Line Okay");
    read = getline(&line, &length, file);
    ok(strcmp(("%s", line), "R )\n") == 0, "Fourth Line Okay");
    fclose(file);
}

void test_convert_char_2_object(){
    struct Output_type output_type;
    output_type.type = 'I';
    output_type.pointer = 0;
    ok(output_type.pointer == 0, "pointer has been set");
    ok(output_type.type == 'I', "type has been set");

    output_type = convert_char_2_object(output_type, '1');
    ok(output_type.type == 'I', "type updated Okay");
    ok(output_type.pointer == 1, "pointer increased Okay");
    ok(output_type.content[0] == '1', "content updated Okay");

    output_type = convert_char_2_object(output_type, '.');
    ok(output_type.type == 'F', "type updated Okay");
    ok(output_type.pointer == 2, "pointer increased Okay");
    ok(output_type.content[1] == '.', "content updated Okay");

    output_type = convert_char_2_object(output_type, '1');
    ok(output_type.type == 'F', "type updated Okay");
    ok(output_type.pointer == 3, "pointer increased Okay");
    ok(output_type.content[2] == '1', "content updated Okay");

    output_type = convert_char_2_object(output_type, ' ');
    ok(output_type.type == 'I', "type updated Okay");
    ok(output_type.pointer == 0, "pointer increased Okay");
    ok(output_type.content[0] == '\0', "content updated Okay");
}
/*
Running the above tests
*/
TESTS{
    test_rest_output_files();
    test_reset_struct();
    test_write_item_to_file();
    test_convert_char_2_object();
}
