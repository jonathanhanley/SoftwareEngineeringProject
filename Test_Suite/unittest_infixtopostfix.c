/*
CS3500 - Software Engineering Project


UNIT TEST - infixtopostfix

Colin Kelleher
Jonathan Hanley
Karol Przestrzelski
Liam de la Cour
*/

/*
Include statements
*/
#include <ctap.h>
#include <stdbool.h>
#include "infixtopostfix.h"
#include "common.h"


/*
*
* Test every combination of operators to ensure equalPrecedence fucntion returns correct value
*
*/
void testEqualPrecedenceFunction(){

  ok(equalPrecedence('+', '+') == true, "+ and + have equal precedence");
  ok(equalPrecedence('+', '-') == true, "+ and - have equal precedence");
  ok(equalPrecedence('-', '-') == true, "- and - have equal precedence");
  ok(equalPrecedence('-', '+') == true, "- and + have equal precedence");

  ok(equalPrecedence('+', '*') == false, "+ and * don't have equal precedence");
  ok(equalPrecedence('+', '/') == false, "+ and / don't have equal precedence");
  ok(equalPrecedence('-', '*') == false, "- and * don't have equal precedence");
  ok(equalPrecedence('-', '/') == false, "- and / don't have equal precedence");

  ok(equalPrecedence('*', '*') == true, "* and * have equal precedence");
  ok(equalPrecedence('*', '/') == true, "* and / have equal precedence");
  ok(equalPrecedence('/', '*') == true, "/ and * have equal precedence");
  ok(equalPrecedence('/', '/') == true, "/ and / have equal precedence");

  ok(equalPrecedence('*', '+') == false, "* and + don't have equal precedence");
  ok(equalPrecedence('*', '-') == false, "* and - don't have equal precedence");
  ok(equalPrecedence('/', '+') == false, "/ and + don't have equal precedence");
  ok(equalPrecedence('/', '-') == false, "/ and - don't have equal precedence");

}

/*
*
* Test every combination of operators to ensure greaterPrecedence fucntion returns correct value
*
*/
void testGreaterPrecedenceFunction() {

  ok(greaterPrecedence('*', '+') == true, "* has greater precedence than +");
  ok(greaterPrecedence('*', '-') == true, "* has greater precedence than -");
  ok(greaterPrecedence('/', '+') == true, "/ has greater precedence than +");
  ok(greaterPrecedence('/', '-') == true, "/ has greater precedence than -");

  ok(greaterPrecedence('*', '*') == false, "* does not have greater precedence than *");
  ok(greaterPrecedence('*', '/') == false, "* does not have greater precedence than /");
  ok(greaterPrecedence('/', '*') == false, "/ does not have greater precedence than *");
  ok(greaterPrecedence('/', '/') == false, "/ does not have greater precedence than /");

  ok(greaterPrecedence('+', '*') == false, "+ does not have greater precedence than *");
  ok(greaterPrecedence('+', '/') == false, "+ does not have greater precedence than /");
  ok(greaterPrecedence('-', '*') == false, "- does not have greater precedence than *");
  ok(greaterPrecedence('-', '/') == false, "- does not have greater precedence than /");

  ok(greaterPrecedence('+', '+') == false, "+ does not have greater precedence than +");
  ok(greaterPrecedence('+', '-') == false, "+ does not have greater precedence than -");
  ok(greaterPrecedence('-', '+') == false, "- does not have greater precedence than +");
  ok(greaterPrecedence('-', '-') == false, "- does not have greater precedence than +");

}

/*
*
* Creates a text file with tokenized input, runs infixtopostfix on it, then compares output FILE
* to ensure correct output
*
*/
void testInfixToPostfixComponent() {

  createTextFile("tokenized.txt", "I 1\nO +\nI 2\nO +\nI 3\n");
  startInfixToPostfix();
  ok(compareTextInFile("postfixed.txt", "1 2 + 3 + ")== 1, "infixtopostfix works correctly on input 1 + 2 + 3");


}

/*
*
* All the test functions
*
*/
TESTS {
  testEqualPrecedenceFunction();
  testGreaterPrecedenceFunction();
  testInfixToPostfixComponent();
}
