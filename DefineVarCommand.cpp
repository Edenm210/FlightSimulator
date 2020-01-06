//
// Created by eden on 23/12/2019.
//

#include <iostream>
#include "DefineVarCommand.h"
#include "VariableMap.h"
#include "Interpreter.h"
#include "ConditionCommand.h"
#include "mutex"

using namespace std;
mutex mtxV;


DefineVarCommand::DefineVarCommand() : Command() {}

DefineVarCommand::~DefineVarCommand() {}

int DefineVarCommand::execute(int index,
                              vector<string> lexerData) { // i is the location of the commandName in the array
  //mtxV.lock();

  string stringToFind = lexerData.at(index); // the word we want to find
  string name, direct;
  if (stringToFind == "var") { // new var declaration

    std::cout << "here" << std::endl;
    name = lexerData.at(index + 1);
    direct = lexerData.at(index + 2);
    cout << name << endl;
    if (direct.compare("=") != 0) {

      string sim = lexerData.at(index + 4);

      mtxV.lock();

      Var* tmpVar = VariableMap::getInstanceVarsMap()->findSimInGen(sim); //getting the VAR*
      cout<<"sii"+tmpVar->getSim()<<endl;

      ///UPDATING THE VAR VALUE
      tmpVar->setDirect (direct);

      VariableMap::getInstanceVarsMap()->updateFlyMap(name, tmpVar);
      mtxV.unlock();

      this->numOfParams = 5;
    } else { // new 'stupid' variable - not pointing to any Var in the simulator only a value
      name = stringToFind;
      mtxV.lock();
      updateValueOfVar(lexerData.at(index + 3), name);
      mtxV.unlock();
      this->numOfParams = 4;
    }
  } else { // the string to find is a variable name - updating value of *existing* var (=)
    mtxV.lock();
    direct = lexerData.at(index + 1);
    updateValueOfVar(lexerData.at(index + 2), stringToFind);
    mtxV.unlock();
    this->numOfParams = 3;
  }
  //mtxV.unlock();
  return this->numOfParams;
}

void DefineVarCommand::updateValueOfVar(string expression, string varName) {
  Interpreter *i1 = new Interpreter();
  Expression *exp = nullptr;
  string varsToSet;
  //creating a string from the variables map, afterwards the Interpreter will use it
  unordered_map<string, Var *> varMap = VariableMap::getInstanceVarsMap()->getFlyVarsMap();
  if (!varMap.empty()) {
    varsToSet = ConditionCommand::varsToString(varMap);
    i1->setVariables(varsToSet);
  }

  try {
    exp = i1->interpret(expression);
    float newValue = exp->calculate();
    unordered_map<string, Var *>::const_iterator
        iter = VariableMap::getInstanceVarsMap()->getFlyVarsMap().find(varName);
    if (iter != VariableMap::getInstanceVarsMap()->getFlyVarsMap().end()) { // the var exists as expected
      iter->second->changeVarValue(newValue); // common VAR*
      //update queue for client by checking if this var need to be updated by client
      if (iter->second->getDirect() == "->") { ///need to change the updateQueue to get the sim name (now its flyName)
        VariableMap::getInstanceVarsMap()->updateVarsQueue(iter->second->getSim(), newValue);
      }
    } else { // new Var insertion to map with "=" direct
      VariableMap::getInstanceVarsMap()->updateFlyMap(varName, new Var("","=",newValue));
      //VariableMap::getInstanceVarsMap()->getFlyVarsMap()[varName] = new Var("", "=", newValue);
    }
  } catch (const char *e) {
    // Deleting a null pointer has no effect, so it is not necessary to check for a null pointer before calling delete.
    delete exp;
    delete i1;
    std::cout << e << std::endl;
  }
}
