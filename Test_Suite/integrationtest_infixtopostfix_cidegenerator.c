#include <ctap.h>
#include <infixtopostfix.h>
#include <codegenerator.h>
int input_index = 0;
int output_index = 0;
int num_tests = 3;
char *inputs[] = {
    //Input 1
    "I 1",
    "O *",
    "I 2",
    "O +",
    "I 3",

    //Input 2
    "F 2.2",
    "O +",
    "I 5",

    //Input 3
    "I 100",
    "O -",
    "F 3.2"
};

char *outputs[] = {
    //Output1
    "LOADINT 1\n",
    "LOADINT 2\n",
    "MUL \n",
    "LOADINT 3\n",
    "ADD \n",

    //Output2
    "LOADFLOAT 2.200000\n",
    "LOADINT 5\n",
    "ADD \n",

    //Output3
    "LOADINT 100\n",
    "LOADFLOAT 3.200000\n",
    "SUB \n",

};

void _create_input(int test_num){

    FILE * file;
    file = fopen("tokenized.txt", "w");
    if (test_num == 0){
        for(int i = input_index; i < 5; i++){
            fprintf(file, "%s\n", inputs[i]);
            input_index ++;
        }

    }
    else if (test_num == 1){
        for(int i = input_index; i < 8; i++){
            fprintf(file, "%s\n", inputs[i]);
            input_index ++;
        }
    }
    else if (test_num == 2){
        for(int i = input_index; i < 11; i++){
            fprintf(file, "%s\n", inputs[i]);
            input_index ++;
        }
    }



    fclose(file);
}

void output_matches_input(int test_num){
        FILE *fp;
        char str[1000];
        char* filename = "codegenerated.txt";
        fp = fopen(filename, "r");
        while (fgets(str, 1000, fp) != NULL){
            is_string(str, outputs[output_index], "TEST %d", test_num);
            output_index++;
        }
    fclose(fp);

}
void test_integration_infixtopostfix_codegenerator(){
    for(int i = 0; i < num_tests; i++){
        _create_input(i);
        startInfixToPostfix();
        startCodeGenerator();
        output_matches_input(i);

    }
}


TESTS{
    test_integration_infixtopostfix_codegenerator();
}
