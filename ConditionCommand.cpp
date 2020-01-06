//
// Created by eden on 02/01/2020.
//

#include <iostream>
#include <string>

#include "ConditionCommand.h"
#include "VariableMap.h"
#include "Interpreter.h"

ConditionCommand::ConditionCommand() {
}

int ConditionCommand::idenOperator(char c) {
  switch (c) {
    case '<':
      return 1;
    case '>':
      return 2;
    case '=':
      return 20;
    default:
      return 0;
  }
}

int ConditionCommand::idenOperator(string s) {
  if (s == "==") {
    return 3;
  } else if (s == "<=") {
    return 4;
  } else if (s == ">=") {
    return 5;
  } else if (s == "!=") {
    return 6;
  } else {
    return 0;
  }
}

// creating a variables string in the form the Interpreter works with
string ConditionCommand::varsToString(unordered_map<string, Var *> varMap) {
  string s;
  for (auto &it: varMap) {
    s.append(it.first);
    s.append("=");
    s.append(to_string(it.second->getVal()));
    s.append(";");
  }
  s.pop_back();
  //cout << s;
  return s;
}

void ConditionCommand::initCondition(string token) {
  int expFlag = 0, operFlag = 0, k = 0;
  char ch;
  //float arg1 = 0, arg2 = 0; // arg1 - left exp, arg2 - right exp
  string varsToSet, exp1, exp2, sign;

  unordered_map<string, Var *> varMap = VariableMap::getInstanceVarsMap()->getFlyVarsMap();

  auto *i1 = new Interpreter();
  Expression *e1 = nullptr;
  Expression *e2 = nullptr;
  varsToSet = varsToString(varMap);
  i1->setVariables(varsToSet);

  /// Calculate the expressions and sign of 'if' condition
  while (!idenOperator(token[k])) {
    exp1.append(1, token[k]);
    k++;
  }
  //calculate the left expression of the token
  e1 = i1->interpret(exp1);
  this->leftArg = e1->calculate();
  //check the operator
  if (idenOperator(token[k + 1])) {
    sign.append(1, token[k]); // adding it to the sign string
    sign.append(1, token[k + 1]);
    this->oper = idenOperator(sign);
    k += 2;
  } else {
    ch = token[k];
    this->oper = idenOperator(ch);
    k++;
  }
  while (k < token.size()) {
    exp2.append(1, token[k]);
    k++;
  }
  e2 = i1->interpret(exp2);
  this->rightArg = e2->calculate();
}

bool ConditionCommand::conditionCheck() {
  switch (this->oper) {
    // <
    case 1:
      if (this->leftArg < this->rightArg) {
        return true;
      }
      return false;
      // >
    case 2:
      if (this->leftArg > this->rightArg) {
        return true;
      }
      return false;
      // ==
    case 3:
      if (this->leftArg == this->rightArg) {
        return true;
      }
      return false;
      // <=
    case 4:
      if (this->leftArg <= this->rightArg) {
        return true;
      }
      return false;
      // >=
    case 5:
      if (this->leftArg >= this->rightArg) {
        return true;
      }
      return false;
      // !=
    case 6:
      if (this->leftArg != this->rightArg) {
        return true;
      }
      return false;
    default:
      break;
  }
}




/*
if ((idenOperator(token[k]))) { // if the function returns 0 - which means the char is not an operator.
if (expFlag==0) { //calculating the left expression
  exp1.append(token);
  e1 = i1->interpret(exp1);
  this->leftArg = e1->calculate();
  continue;
} else { //calculating the right expression
  exp2.append(token);
  e2 = i1->interpret(exp2);
  this->rightArg = e2->calculate();
  continue;
}
}
//we are getting to this "if" only if the char is an operator. checking if also the next char is an operator.
if (idenOperator(token[k + 1])) { // !=0 which means the next char is an operator - two chars operator
sign.append(1, token[k]); // adding it to the sign string
sign.append(1, token[k + 1]);
this->oper = idenOperator(sign); // converting the string to an int that represents the operator
operFlag = 1; // the operator is ready
} else if (!operFlag) { // the next char is not an operator this is a one char operator
ch = token[k];
this->oper = idenOperator(ch); //converting the char to an int that represents the operator
}
expFlag = 1; // the leftExp is ready because we reached to the operator. now calculating the rightExp.
}
 */