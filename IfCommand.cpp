//
// Created by eden on 21/12/2019.
//

#include "IfCommand.h"

#include "vector"

using namespace std;

/* calling the father constructor.
the params is the number of steps to advance in the array after execute */
IfCommand::IfCommand(int params) : Command() { this->numOfParams = params; }


int IfCommand::execute(int i, vector<string> lexerData) {

  /////////////////////////////////////////////////////////////// ACTION
  return this->numOfParams;
};