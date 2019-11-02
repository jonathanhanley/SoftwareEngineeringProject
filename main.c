// 
// Created by Karol Przestrzelski
//

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