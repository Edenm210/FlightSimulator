//
// Created by eden on 21/12/2019.
//

#ifndef PROJECT3__COMMAND_H_
#define PROJECT3__COMMAND_H_

#include "Command.h"
#include "vector"
#include <string>


using namespace std;


class Command {

 public:
  int numOfParams = -1;
  virtual int execute(int i, vector<string> lexerData) = 0;
  virtual ~Command() {}

};



#endif //PROJECT3__COMMAND_H_
