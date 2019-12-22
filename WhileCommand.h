//
// Created by eden on 21/12/2019.
//

#ifndef PROJECT3__WHILECOMMAND_H_
#define PROJECT3__WHILECOMMAND_H_

#include "Command.h"
#include "vector"

using namespace std;

class WhileCommand: public Command {

 public:
  WhileCommand(int params);
  virtual ~WhileCommand() {}
  int execute(int i, vector<string> lexerData) override; // i is the location of the commandName in the array

};

#endif //PROJECT3__WHILECOMMAND_H_
