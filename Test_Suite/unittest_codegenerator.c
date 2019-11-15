/*
CS3500 - Software Engineering Project

UNIT TEST - Code Generator

Colin Kelleher
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
*/


/*
Include statements
*/
#include <ctap.h>
#include "codegenerator.h"
#include "common.h"

/*
Creating a text file with an input, running the code generator
and checking the output file to ensure the output is correct
and matches the instruction set
*/
void testCodeGeneratorComponent() {
  createTextFile("postfixed.txt", "1 2 3 * + \n");
  printf(" ");
  startCodeGenerator();
  compareTextInFile("codegenerated.txt", "LOADINT 1\nLOADINT 2\nLOADINT 3\nMUL \nADD \n");

}

/*
Test to check the classifyChar function within the code generator
Checks to ensure that the type is updating correctly
according to the appropriate symbol
*/
void testClassifyChar () {
  CharacterType *charType = newCharacterType();
  charType->type = 1;
  charType->pointer - 0;

  classifyChar(charType,'-');
  ok(charType->type == 5, "Type updated to 5 - indicating a '-' symbol");
  classifyChar(charType,'+');
  ok(charType->type == 4, "Type updated to 4 - indicating a '+' symbol");
  classifyChar(charType,'/');
  ok(charType->type == 3, "Type updated to 3 - indicating a '/' symbol");
  classifyChar(charType,'*');
  ok(charType->type == 2, "Type updated to 2 - indicating a '*' symbol");
  classifyChar(charType,'.');
  ok(charType->type == 0, "Type updated to 0 - indicating float");
  
}

/*
Runs the above tests
*/
TESTS {
  testCodeGeneratorComponent();
  testClassifyChar();
}
