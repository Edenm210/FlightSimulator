//
// Created by eden on 17/12/2019.
//

#include <iostream>
#include "Parser.h"
#include "CommandsMap.h"
#include "vector"
#include "WhileCommand.h"
#include "DefineVarCommand.h"

using namespace std;

void Parser::ParseCommand(vector<string> lexerData) {
  try {
    unordered_map<string, Command *> commandMap = CommandsMap::getInstanceCommandMap()->getCommandMap();

    int index = 0;
    while (index < lexerData.size()) {
      string stringToFind = lexerData.at(index); // the word we want to find
      Command *c;

      //the command does not match so it is a variable name - updating variable value (=)
      if(commandMap.find(stringToFind) == commandMap.end()) {
        c = new DefineVarCommand();
      } else {
        c= commandMap.find(stringToFind)->second; // getting the command
      }

      index += c->execute(index, lexerData);

    }
  } catch (const char *e) {
    std::cout << e << std::endl;
  }
}








