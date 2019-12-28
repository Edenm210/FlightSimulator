//
// Created by eden on 23/12/2019.
//

#include <iostream>
#include "DefineVarCommand.h"
#include "VariableMap.h"
#include "Interpreter.h"
using namespace std;

DefineVarCommand::DefineVarCommand() : Command() {}

DefineVarCommand::~DefineVarCommand() {delete this->command;}

int DefineVarCommand::execute(int index, vector<string> lexerData) { // i is the location of the commandName in the array
  unordered_map<string, Var *> variablesMap = VariableMap::getInstanceVarsMap()->getFlyVarsMap(); // variables in the fly.txt

    string stringToFind = lexerData.at(index); // the word we want to find
    string name = lexerData.at(index + 1);
    string direct = lexerData.at(index + 2);
    if (stringToFind=="var") { // new var declaration
      if(direct.compare("=")!=0){
        string sim = lexerData.at(index + 4);
        variablesMap[name] = new Var(sim, direct, 0);
        this->numOfParams = 5;
      } else { // a 'stupid' variable - not pointing to any Var in the simulator only a value
        updateValueOfExistingVar(lexerData.at(index + 3),name);
        this->numOfParams = 4;

        //variablesMap[name] = new Var("", direct, index+);
      }

    } else { // updating value of existing var (=)
      updateValueOfExistingVar(lexerData.at(index + 2), stringToFind);
      this->numOfParams = 3;
    }
  return this->numOfParams;
}

//returning the numOfParams
void DefineVarCommand::updateValueOfExistingVar(string expression, string varName) {
  Interpreter *i1 = new Interpreter();
  Expression *exp = nullptr;

  try {
    exp = i1->interpret(expression);
    float newValue = exp->calculate();
    unordered_map<string, Var *>::const_iterator iter = VariableMap::getInstanceVarsMap()->getFlyVarsMap().find(varName);
    if (iter!=VariableMap::getInstanceVarsMap()->getFlyVarsMap().end()) { // the var exists
      iter->second->changeVarValue(newValue);
    } else {
      VariableMap::getInstanceVarsMap()->getFlyVarsMap()[varName] = new Var("", "=", newValue);
    }
  } catch (const char *e) {
    if (exp!=nullptr) {
      delete exp;
    }
    if (i1!=nullptr) {
      delete i1;
    }
    std::cout << e << std::endl;
  }
}
