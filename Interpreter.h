//
// Created by eden on 19/11/2019.
//

#ifndef MYPROJECT__INTERPRETER_H_
#define MYPROJECT__INTERPRETER_H_

#include <queue>
#include <map>
#include <string.h>
#include "Expression.h"
using namespace std;

class Interpreter {
 private:
  map<string, float> variables_map;

 public:
  Interpreter(); // empty constructor
  ~Interpreter();

  Expression *interpret(string input);
  Expression *newExpression(queue<string> queue);

  int precedence(char c);

  int checkType(char c);
  void setVariables(string variables_string);

  // changing the input to postfix
  queue<string> infixToPostfix(string s);

  Expression *findVarInMap(string variable);

};

bool checkUnary(char c);

#endif //MYPROJECT__INTERPRETER_H_
