//
// Created by eden on 17/12/2019.
//

#include <iostream>
#include "Parser.h"
#include "CommandsMap.h"
#include "VariableMap.h"
#include "vector"
#include "WhileCommand.h"
#include "IfCommand.h"
#include "Interpreter.h"

using namespace std;

void Parser::ParseCommand(vector<string> lexerData) {
  try {
    unordered_map<string, Command *> commandMap = CommandsMap::getInstanceCommandMap()->getCommandMap();

    int index = 0;
    while (index < lexerData.size()) {
      string stringToFind = lexerData.at(index); // the word we want to find
      Command *c = commandMap.find(stringToFind)->second; // getting the command

      if (c!=NULL)
        index += c->execute(index, lexerData);
    }
  } catch (const char *e) {
    std::cout << e << std::endl;

  }
}








