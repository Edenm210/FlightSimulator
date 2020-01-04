//
// Created by eden on 17/12/2019.
//

#include <iostream>
#include "Parser.h"
#include "CommandsMap.h"
#include <vector>
#include "DefineVarCommand.h"
#include "VariableMap.h"


using namespace std;

void Parser::ParseCommand(vector<string> lexerData) {
  try {
    unordered_map<string, Command *> commandMap = CommandsMap::getInstanceCommandMap()->getCommandMap();

    int index = 0;
    int size =  lexerData.size();
    while (index < size) {
      string stringToFind = lexerData.at(index); // the word we want to find
      Command *c;

      unordered_map<string, Command*>::const_iterator
          iter = commandMap.find(stringToFind);
      //the command does not match so it is a variable name - updating variable value (=)
      if(iter == commandMap.end()) {
        c = new DefineVarCommand();
      } else {

        c= iter->second; // getting the command
      }
      cout<<stringToFind + " Now executing"<<endl;
      index += c->execute(index, lexerData);
      cout<<stringToFind + " Executed"<<endl;

    }
    VariableMap::setBool(true);
  } catch (const char *e) {
    std::cout << e << std::endl;
  }
}








