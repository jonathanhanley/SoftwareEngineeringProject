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
Include statements
*/
void testClassifyChar () {
  CharacterType *chartype = newCharacterType();

}

/*
Runs the above tests
*/
TESTS {
  testCodeGeneratorComponent();
}
