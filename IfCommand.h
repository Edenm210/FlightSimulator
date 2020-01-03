//
// Created by eden on 21/12/2019.
//

#ifndef PROJECT3__IFCOMMAND_H_
#define PROJECT3__IFCOMMAND_H_

#include <string>
#include <vector>
#include "Command.h"
#include "Var.h"
#include "ConditionCommand.h"
#include <unordered_map>

using namespace std;

class IfCommand : public ConditionCommand {

 public:
  IfCommand();
  ~IfCommand() override;

  int execute(int i, vector<string> lexerData) override; // i is the location of the commandName in the array

  //string getExp(string s);
};

#endif //PROJECT3__IFCOMMAND_H_
