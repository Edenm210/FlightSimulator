//
// Created by eden on 21/12/2019.
//

#ifndef PROJECT3__IFCOMMAND_H_
#define PROJECT3__IFCOMMAND_H_

#include <string>
#include "vector"
#include "Command.h"

using namespace std;

class IfCommand : public Command {

 public:
  IfCommand(int params);
  virtual ~IfCommand() {}
  int execute(int i, vector<string> lexerData) override; // i is the location of the commandName in the array

};

#endif //PROJECT3__IFCOMMAND_H_
