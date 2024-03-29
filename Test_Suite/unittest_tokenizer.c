/*
CS3500 - Software Engineering Project


UNIT TEST - Tokenizer

Colin Kelleher
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
*/


/*
Include statements
*/
#include <ctap.h>
#include <tokenizer.h>

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
Testing if a character is added to the struct in the
correct way.
Adds characters to the struct,
testing if the:
    1) type attribute updates
    2) pointer updates
    3) content updates
*/
void test_convert_char_2_object(){
    CharacterType *output_type = newCharacterType();
    output_type->type = 1;
    output_type->pointer = 0;
    ok(output_type->pointer == 0, "pointer has been set");
    ok(output_type->type == 1, "type has been set");

    convert_char_2_object(output_type, '1');
    ok(output_type->type == 1, "type updated Okay");
    ok(output_type->pointer == 1, "pointer increased Okay");
    ok(output_type->content[0] == '1', "content updated Okay");

    convert_char_2_object(output_type, '.');
    ok(output_type->type == 0, "type updated Okay");
    ok(output_type->pointer == 2, "pointer increased Okay");
    ok(output_type->content[1] == '.', "content updated Okay");

    convert_char_2_object(output_type, '1');
    ok(output_type->type == 0, "type updated Okay");
    ok(output_type->pointer == 3, "pointer increased Okay");
    ok(output_type->content[2] == '1', "content updated Okay");

    convert_char_2_object(output_type, ' ');
    ok(output_type->type == 1, "type updated Okay");
    ok(output_type->pointer == 0, "pointer increased Okay");
    ok(output_type->content[0] == '\0', "content updated Okay");
}
/*
Running the above tests
*/
TESTS{
    test_rest_output_files();
    printf("Why printf fixes ctap idk");
    test_convert_char_2_object();
}
