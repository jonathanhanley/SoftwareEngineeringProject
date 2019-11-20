/*
CS3500 - Software Engineering Project

Main file that runs all the other unittests together

Colin Kelleher
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
*/

/*
Include statements
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
listing all the test files below
*/
char *files[] = {
    "test_codegenerator.t",
    "test_common.t",
    "test_infixtopostfix.t",
    "test_stack.t",
    "test_tokenizer.t",
    "test_virtualmachine.t",
    "test_tokenizer_infixtopostfix.t",
    "test_infixtopostfix_codegenerator.t",
    "test_system.t"
};

/*
Checking if the files exist and then executing them
according to terminal commands
*/
int main(){
    char cmd[300] = "prove";
    for (int i=0; i<sizeof(files)/sizeof(files[0]); i++){
        // Check if this file exists
        FILE *f;
        f = fopen(files[i], "r");
        printf("%s\n", files[i]);
        if (f == NULL) continue;
        // Execute ./test_file
        printf("Found tests for %s\n", files[i]);
        sprintf(cmd, "%s ./%s", cmd, files[i]);
    }
    system(cmd);
}
