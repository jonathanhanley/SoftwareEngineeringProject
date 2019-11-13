/*
CS3500 - Software Engineering Project

Testing with Tap

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
* Comment here
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
* Comment here
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

void testInfixToPostfixComponent() {

  /*
  write to first file (with name, char array ie string);

  run the function, so main()

  compare output file with string:
  */

  createTextFile("tokenized.txt", "I 1\nO +\nI 2\nO +\nI 3\n");
  startInfixToPostfix();

  int compare = compareTextInFile("postfixed.txt", "1 2 + 3 + ");
  ok(compare == 1, "infixtopostfix works correctly on input 1 + 2 + 3");

}

/*
*
* Comment here
*
*/
TESTS {
  testEqualPrecedenceFunction();
  testGreaterPrecedenceFunction();
  testInfixToPostfixComponent();
}
