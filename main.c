/*
CS3500 - Software Engineering Project

Karol Przestrzelski
Colin Kelleher
Jonathan Hanley
Liam de la Cour
*/

/*
This is the main file that starts all the seperate calculator components
*/
#include "tokenizer.h"
#include "infixtopostfix.h"
#include "codegenerator.h"
#include "virtualmachine.h"

int main(){
    startTokenizer();
    startInfixToPostfix();
    startCodeGenerator();
    startVirtualMachine();
}