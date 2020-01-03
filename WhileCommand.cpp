//
// Created by eden on 21/12/2019.
//

#include <string>
#include "WhileCommand.h"
#include "vector"
#include "Interpreter.h"
#include "Var.h"
#include "IfCommand.h"
#include "VariableMap.h"
#include "CommandsMap.h"
#include "DefineVarCommand.h"
#include <unordered_map>

using namespace std;

/* calling the father constructor.
the params is the number of steps to advance in the array after execute */
WhileCommand::WhileCommand() : ConditionCommand() {}
WhileCommand::~WhileCommand() {}

int WhileCommand::execute(int i, vector<string> lexerData) {
  int numOfCommandsInWhile = stoi(lexerData.at(i + 2)); // number of commands inside the "while"
  // advance from the token 'while' to the next token - the argument in the 'if' condition
  string token = lexerData.at(i + 1);

  ConditionCommand::initCondition(token); // initializing the condition Expressions on both sides+operator

  /// END OF Calculate the expressions and sign of 'while' condition

  int firstCommand = i+3; // saving the index of the first command so we can go back to it in every iteration
  //while the condition is true
  while (ConditionCommand::conditionCheck()) {
    i = firstCommand;
    // executing all the commands in the loop
    for (int j = 1; j <= numOfCommandsInWhile; j++) {
      token = lexerData[i]; // the commandName to execute
      unordered_map<string, Command *> commandMap = CommandsMap::getInstanceCommandMap()->getCommandMap();
      Command *c;

      //the command does not match so it is a variable name - updating variable value (=)
      if (commandMap.find(token)==commandMap.end()) {
        c = new DefineVarCommand();
      } else {
        c = commandMap.find(token)->second; // getting the command
      }
      i += c->execute(i, lexerData); // moving to the next command in the loop
    }
  }
  this->numOfParams = i-(firstCommand-3);
  return numOfParams;
};







