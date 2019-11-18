/*
CS3500 - Software Engineering Project


INTEGRATION TEST - Tokenizer & Infixtopostfix

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
#include <infixtopostfix.h>

/*
Creating sample inputs
*/
char *inputs[] = {
    "14 + 52",
    "12.5*(12+5)",
    "(10 * 10) + 3 -2",
    "1* 1 * 12 - 4 / (1+1)",
    "0 * 0 + 1"
};

/*
Creating correct outputs for the sample inputs
*/
char *outputs[] = {
    "14 52 + ",
    "12.500000 12 5 + * ",
    "10 10 * 3 + 2 - ",
    "1 1 * 12 * 4 1 1 + / - ",
    "0 0 * 1 + "
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
    post_fix_file = fopen("postfixed.txt", "r");
    read = getline(&line, &length, post_fix_file);

    return line;
}
/*
Running the Tokenizer and InfixToPostfix converter
and ensursing that the inputs/outputs are appropriate
*/
void test_integration_tokenizer_infixtopostfix(){
    char *line;
    char *item;
    for (int test_num = 0; test_num < 5; test_num++){
        _create_input(test_num);
        startTokenizer();
        startInfixToPostfix();
        line = _get_line(test_num);
        item = outputs[test_num];
        is_string(("%s", item), line, "on input %s", inputs[test_num]);
    }
}

/*
Running the above tests
*/
TESTS{
    test_integration_tokenizer_infixtopostfix();
}
