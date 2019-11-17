/*
CS3500 - Software Engineering Project


UNIT TEST - Virtual Machine

Colin Kelleher
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
*/


/*
Include statements
*/
#include <ctap.h>
#include "virtualmachine.h"
#include "stack.h"
#include "common.h"
#include "codegenerator.h"
#include "tokenizer.h"
#include "infixtopostfix.h"


int input_index = 0;
int output_index = 0;
int num_tests = 7;


char *inputs[] = {
    "14 + 52",
    "10 - 2",
    "10 / 2",
    "5 * 4",
    "( 12 + 5 ) * 2",
    "( 15 + 5 ) / 2",
    "12.5 + 5.5"
};

char *outputs[] = {
    "66\n",
    "8\n",
    "5\n",
    "20\n",
    "34\n",
    "10\n",
    "18\n"
};

void _create_input(int test_num){
    char *item = inputs[test_num];
    FILE * file;
    file = fopen("input.txt", "w");
    fprintf(file, "%s", item);
    fclose(file);

}

char * _get_line(int test_num){
    FILE * post_fix_file;
    char * line;
    size_t length = 0;
    ssize_t read;
    post_fix_file = fopen("log.txt", "r");
    read = getline(&line, &length, post_fix_file);

    return line;
}

void output_matches_input(int test_num){
        FILE *fp;
        char str[1000];
        char* filename = "log.txt";
        fp = fopen(filename, "r");
        while (fgets(str, 1000, fp) != NULL){
            is_string(str, outputs[output_index], "TEST %d", test_num);
            output_index++;
        }
    fclose(fp);

}

void testSystemTest(){
    char *line;
    char *item;
  for(int i = 0; i < num_tests; i++){
        _create_input(i);
        FILE *saved = stdout;
        stdout = fopen("log.txt", "w");
        startTokenizer();
        startInfixToPostfix();
        startCodeGenerator();
        startVirtualMachine();
        fclose(stdout);
        output_matches_input(i);
        remove("log.txt");
   }
}


/*
Running the above tests
*/
TESTS {
    testSystemTest();
}
