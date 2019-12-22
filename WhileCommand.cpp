//
// Created by eden on 21/12/2019.
//

#include <string>
#include "WhileCommand.h"
#include "vector"

using namespace std;

/* calling the father constructor.
the params is the number of steps to advance in the array after execute */
WhileCommand::WhileCommand(int params) : Command() { this->numOfParams = params; }


int WhileCommand::execute(int i, vector<string> lexerData) {
  Expression
  for(int counter=1;counter<=this->numOfParams;counter++) {
  }

  /////////////////////////////////////////////////////////////// ACTION
  return this->numOfParams;
};

