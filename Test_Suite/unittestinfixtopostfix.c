#include <ctap.h>
#include <stdbool.h>

#include "infixtopostfix.h"

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

TESTS {
  testEqualPrecedenceFunction();
  testGreaterPrecedenceFunction();
}
