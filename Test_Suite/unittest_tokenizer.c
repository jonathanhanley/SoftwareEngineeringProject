#include <ctap.h>
#include "tokenizer.c"

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
TESTS{
    test_rest_output_files();
    test_reset_struct();
}