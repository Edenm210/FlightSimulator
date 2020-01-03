//
// Created by eden on 02/01/2020.
//

#ifndef PROJECT3__CONDITIONCOMMAND_H_
#define PROJECT3__CONDITIONCOMMAND_H_

#include <unordered_map>
#include "Command.h"
#include "Var.h"
#include <string>

class ConditionCommand : public Command{
 private:
  float leftArg;
  float rightArg;
  int oper;

 public:
  ConditionCommand();
  static int idenOperator(string s);
  static int idenOperator(char c);
  static string varsToString(unordered_map<string, Var*> varMap);

  void initCondition(string s);

  bool conditionCheck();


  virtual ~ConditionCommand(){}


};

#endif //PROJECT3__CONDITIONCOMMAND_H_
