//
// Created by eden on 23/12/2019.
//

#ifndef PROJECT3__DEFINEVARCOMMAND_H_
#define PROJECT3__DEFINEVARCOMMAND_H_

#include <string>
#include "Command.h"
#include "vector"

using namespace std;

class DefineVarCommand : public Command{
 private:
  Command* command;

 public:
  DefineVarCommand();
  virtual ~DefineVarCommand(); //////////////////////////////////////////////////////////////////////////////////////////////////////
  int execute(int i, vector<string> lexerData) override; // i is the location of the commandName in the array

  void updateValueOfExistingVar(string exp, string varName);


  };

#endif //PROJECT3__DEFINEVARCOMMAND_H_
