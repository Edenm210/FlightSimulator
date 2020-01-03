//
// Created by eden on 23/12/2019.
//

#include <iostream>
#include "DefineVarCommand.h"
#include "VariableMap.h"
#include "Interpreter.h"
#include "ConditionCommand.h"
using namespace std;

DefineVarCommand::DefineVarCommand() : Command() {}

DefineVarCommand::~DefineVarCommand() {}

int DefineVarCommand::execute(int index,
                              vector<string> lexerData) { // i is the location of the commandName in the array

  string stringToFind = lexerData.at(index); // the word we want to find
  string name = lexerData.at(index + 1);
  string direct = lexerData.at(index + 2);
  if (stringToFind=="var") { // new var declaration
    if (direct.compare("=")!=0) {
      string sim = lexerData.at(index + 4);
      VariableMap::getInstanceVarsMap()->getFlyVarsMap()[name] = new Var(sim, direct, 0);
      this->numOfParams = 5;
    } else { // new 'stupid' variable - not pointing to any Var in the simulator only a value
      updateValueOfVar(lexerData.at(index + 3), name);
      this->numOfParams = 4;
    }
  } else { // the string to find is a variable name - updating value of *existing* var (=)
    updateValueOfVar(lexerData.at(index + 2), stringToFind);
    this->numOfParams = 3;
  }
  return this->numOfParams;
}

void DefineVarCommand::updateValueOfVar(string expression, string varName) {
  Interpreter *i1 = new Interpreter();
  Expression *exp = nullptr;
  string varsToSet;
  //creating a string from the variables map, afterwards the Interpreter will use it
  unordered_map<string, Var *> varMap = VariableMap::getInstanceVarsMap()->getFlyVarsMap();
  varsToSet = ConditionCommand::varsToString(varMap);
  i1->setVariables(varsToSet);

  try {
    exp = i1->interpret(expression);
    float newValue = exp->calculate();
    unordered_map<string, Var *>::const_iterator
        iter = VariableMap::getInstanceVarsMap()->getFlyVarsMap().find(varName);
    if (iter!=VariableMap::getInstanceVarsMap()->getFlyVarsMap().end()) { // the var exists
      iter->second->changeVarValue(newValue);
    } else { // new Var insertion to map
      VariableMap::getInstanceVarsMap()->getFlyVarsMap()[varName] = new Var("", "=", newValue);
    }
  } catch (const char *e) {
    // Deleting a null pointer has no effect, so it is not necessary to check for a null pointer before calling delete.
    delete exp;
    delete i1;
    std::cout << e << std::endl;
  }
}
