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


void testCodeGeneratorComponent() {

  createTextFile("postfixed.txt", "1 2 3 * + \n");
  printf(" ");
  startCodeGenerator();
  compareTextInFile("codegenerated.txt", "LOADINT 1\nLOADINT 2\nLOADINT 3\nMUL \nADD \n");

}

TESTS {
  testCodeGeneratorComponent();
}
