//
// Created by eden on 19/11/2019.
//

#include <stack>
#include <iostream>
#include "Interpreter.h"
#include "Value.h"
#include "BinaryOperator.h"
#include "UnaryOperator.h"
#include "Variable.h"

Interpreter::Interpreter() {}
Interpreter::~Interpreter() { this->variables_map.clear(); } // clearing the variables map

int Interpreter::precedence(char c) {
  // checking the precedence of the operations
  if (c=='+' || c=='-') return 1;
  else if (c=='/' || c=='*') return 2;
  else if (c=='(' || c==')') return -1;
  else return 3; // if unary operator - ^/~

}

// interpreting the string (the input) to Expression checkType
Expression *Interpreter::interpret(string input) {
  queue<string> postfix = infixToPostfix(input);
  return newExpression(postfix);
}

queue<string> Interpreter::infixToPostfix(string s) {
  //stack for operators
  stack<char> stack;
  queue<string> postfix_queue;
  string str;
  int num_dots = 0;

  unsigned int i = 0;
  while (i!=s.length()) { // did not reach to the end of the input string
    switch (checkType(s[i])) {
      // operator
      case 1:
        if (s[i]=='(') {
          stack.push(s[i]);
        } else if (s[i]==')') {
          while (!stack.empty() && stack.top()!='(') {
            str += stack.top(); // changing the char to string
            postfix_queue.push(str);
            stack.pop();
            str.clear();
          }
          if (!stack.empty()) { stack.pop(); }
          else { throw "Error: missing Parenthesis"; }
        }
          // +,-,*,/
        else {
          // the last place in the string
          if (i==(s.length() - 1)) { throw "Error: operator at the end of the expression"; }
            // the first place in the string
          else {
            if (s[i + 1]=='*' || s[i + 1]=='/' || s[i + 1]=='+' || s[i + 1]=='-') {
              throw "Error: Invalid Input - two operators next to each other";
            } else {
              if (i==0) {
                if (s[i]=='*'
                    || s[i]=='/') { throw "Error: Binary operator can not be at the start of the expression"; }
                  // to differ between Unary and Binary - inserting other symbol to the stack
                else if (s[i]=='+') { stack.push('^'); }
                else { stack.push('~'); } // s[i] == '-'
              } else { //the operation is not at the edges of the string
                if (s[i - 1]=='(') {
                  if (s[i]=='+') { stack.push('^'); }
                  else { stack.push('~'); } // s[i] == '-'
                } else {
                  while (!stack.empty()
                      && precedence(s[i]) <= precedence(stack.top())) // as long as the precedes is higher in the stack
                  {
                    str += stack.top();// changing the char to string
                    postfix_queue.push(str);
                    stack.pop();
                    str.clear();
                  }
                  stack.push(s[i]);
                }
              }
            }
          }
        }
        i++;
        break;
        // number
      case 2:
        // did not get to the end and in number type
        while ((i!=s.length()) && checkType(s[i])!=1) {
          if (checkType(s[i])==3) { throw "Error: variable starts with a number"; }
          if (s[i]=='.') { num_dots++; }
          str += s[i];
          i++;
        }

        if (str[0]=='.') { throw "Error: dot at the beginning"; }
        if (num_dots > 1) { throw "Error: more than one dot in a number"; }
        if ((str[str.length() - 1])=='.') { throw "Error: dot at the end of a number"; }

        postfix_queue.push(str); // end of the string
        str.clear();
        num_dots = 0;
        break;
        // alphabetic - variable
      case 3:
        while ((i!=s.length()) && (checkType(s[i])!=1)) { // until there is not an operator it is a variable
          if (s[i]=='.') { throw "Error: can not include dot at variable name"; }
          str += s[i];
          i++;
        }
        postfix_queue.push(str); // end of the string
        str.clear();
        break;
      default:
        if (s[i]==' ') {
          i++;
          continue;
        } else {
          throw "Error: invalid character in the input string";
        }
    }
  }
  // adding the rest of the stack to the queue
  while (!stack.empty()) {
    str += stack.top();
    postfix_queue.push(str);
    stack.pop();
    str.clear(); // emptying the string
  }
  return postfix_queue;
}

void Interpreter::setVariables(string variables_string) {
  bool new_var = true;
  string equation_side = "left";
  string var_name, var_value;
  for (unsigned int i = 0; i <= variables_string.length(); i++) {
    if (variables_string[i]==';' || i==variables_string.length()) { // new variable
      new_var = true;
      equation_side = "left";
      if (var_value[0]=='-') {
        var_value.erase(0, 1);
        this->variables_map[var_name] = (-1)*stof(var_value);
      } else if (var_value[0]=='+') {
        var_value.erase(0, 1);
        this->variables_map[var_name] = stof(var_value);
      } else { this->variables_map[var_name] = stof(var_value); } // inserting the variable to the variables map
      var_name.clear();
      var_value.clear();
      continue;
    }

    if (new_var) {
      if (!isalpha(variables_string[i])) { throw "Error: Variable name must start with a letter"; }
      new_var = false;
    }

    if (equation_side.compare("left")==0) {
      if (variables_string[i]=='-') {
        break;
      } else {
        if ((checkType(variables_string[i])!=3) && !isdigit(variables_string[i]) && variables_string[i]!='=') {
          throw "Error: invalid character in a variable name";
        }
      }

        if (variables_string[i]=='=') {
          equation_side = "right";
          continue;
        }
        var_name.append(1, variables_string[i]); // adding one char to the string - 'one time'

    }
      // equation_side == "right"
    else {
      if ((checkType(variables_string[i])!=2) && variables_string[i]!='-'
          && variables_string[i]!='+') { throw "Error: Variable value is invalid"; }
      var_value.append(1, variables_string[i]);
    }

  }
}

Expression *Interpreter::newExpression(queue<string> queue) {
  stack<Expression *> exp_stack;
  Expression *left_exp;
  Expression *right_exp;
  Expression *unary_exp;
  while (!queue.empty()) {
    // it is a variable
    if (checkType(queue.front()[0])==3) {
      exp_stack.push(findVarInMap(queue.front()));
      //queue.pop();
    }
      // it is a number (no starting with a dot)
    else if (isdigit(queue.front()[0])) {
      exp_stack.push(new Value(stof(queue.front()))); // converting the string to float
      //queue.pop();
    }
      // operator - binary
    else if (checkType(queue.front()[0])==1) {
      right_exp = exp_stack.top();
      exp_stack.pop();
      left_exp = exp_stack.top();
      exp_stack.pop();

      switch (queue.front()[0]) {
        case '+':exp_stack.push(new Plus(left_exp, right_exp));
          break;
        case '-':exp_stack.push(new Minus(left_exp, right_exp));
          break;
        case '/':exp_stack.push(new Div(left_exp, right_exp));
          break;
        case '*':exp_stack.push(new Mul(left_exp, right_exp));
          break;
        default: break;
      }
    }
      // operator - unary
    else {
      unary_exp = exp_stack.top(); // not really a 'right' expression, because unary only have one expression
      exp_stack.pop();
      if (queue.front()[0]=='^') {
        exp_stack.push(new UPlus(unary_exp));
      } else exp_stack.push(new UMinus(unary_exp));
    }

    queue.pop();
  }
  this->variables_map.clear(); // after creating the expression, deleting all the variables
  return exp_stack.top(); // the expression
}

Expression *Interpreter::findVarInMap(string variable) {
  map<string, float>::iterator iterator;
  iterator = variables_map.find(variable); // finding the variable in the map
  if (iterator!=variables_map.end()) {
    return new Variable(variable, iterator->second);
  } else throw "Error: failed finding the variable inserted in input";
}

int Interpreter::checkType(char c) {
  if (c=='*' || c=='/' || c=='+' || c=='-' || c==')' || c=='(') return 1; // operator type
  else if ((c >= '0' && c <= '9') || c=='.') return 2; // number type
  else if (isalpha(c) || c=='_') return 3; // alphabetic type

  return -1;
}