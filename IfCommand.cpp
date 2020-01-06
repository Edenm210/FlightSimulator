//
// Created by eden on 21/12/2019.
//

#include "IfCommand.h"
#include "Variable.h"
#include "Command.h"
#include <vector>
#include <list>
#include <unordered_map>
#include "Interpreter.h"
#include "Expression.h"
#include "Var.h"
#include "CommandsMap.h"
#include "VariableMap.h"
#include "ConditionCommand.h"
#include "DefineVarCommand.h"

using namespace std;

/* calling the father constructor.
the params is the number of steps to advance in the array after execute */
IfCommand::IfCommand() : ConditionCommand() {}
IfCommand::~IfCommand() {}

//trim the vector from the start after every execution / var definition
int IfCommand::execute(int i, vector<string> lexerData) {
  int j, k = 0, moveIndex = 0;// number of steps we will need to proceed in the lexerData after finishing the execute

  // advance from the token 'if' to the next token - the argument in the 'if' condition
  i++;
  string token = lexerData.at(i);
  ConditionCommand::initCondition(token); // initializing the condition Expressions on both sides+operator
  moveIndex += 2; // getting to the numOfCommands inside the loop

  /// END OF Calculate the expressions and sign of 'if' condition
  i++;
  token = lexerData[i]; //num of command inside the "if" - as a string
  k = stoi(token); // number of commands inside the "if" - as an int
  i++; //the first command index in lexerData
  moveIndex++; // the firstCommand in loop index

  //checking if the condition is true
  if (ConditionCommand::conditionCheck()) {
    //k is number of commands to execute
    for (j = 0; j < k; j++) {
      token = lexerData[i]; // the commandName to execute
      unordered_map<string, Command *> commandMap = CommandsMap::getInstanceCommandMap()->getCommandMap();

      Command* command = CommandsMap::getInstanceCommandMap()->findCommandInMap(token); //getting the VAR*

      //the command does not match so it is a variable name - updating variable value (=)
      if(command == NULL) {
        command = new DefineVarCommand();
      }


      //have to check this line!!!!!!
      moveIndex += command->execute(i, lexerData);
      i += moveIndex; // moving to the next command in the loop
    }
  }
  this->numOfParams = moveIndex;
  return numOfParams;
}




/*
   for (j = i; j < lexerData.size(); j++) {
       arg = lexerData.at(j);
       //didn't find the element
       if (varMap.find(arg) == varMap.end()) {
           if (numFlag == 0 && lexer::isNumber(arg)) {
               num1 = stof(arg);
               numFlag = 1;
           } else if (numFlag == 1 && lexer::isNumber(arg)) {
               num2 = stof(arg);
           } else if ((arg.length() == 1)) {
               ch = arg[0];
               oper = idenOperator(ch);
           } else if (arg.length() == 2) {
               oper = idenOperator(arg);
           } else {
               //throw "Couldn't find Variable (ifCommand)";
               continue;
           }
       } else if (varFlag == 0 && !lexer::isNumber(arg)) {
           var1 = varMap[arg];
           varFlag = 1;
       } else if (varFlag == 1 && !lexer::isNumber((arg))) {
           var2 = varMap[arg];
       }
   }
   switch (oper) {
       case 1:
           break;
       case 2:
           break;
       case 3:
           break;
       case 4:
           break;
       case 5:
           break;
       default:
           break;
   }
   */