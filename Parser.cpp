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

      Command* command = CommandsMap::getInstanceCommandMap()->findCommandInMap(stringToFind); //getting the VAR*

      //the command does not match so it is a variable name - updating variable value (=)
      if(command == NULL) {
        command = new DefineVarCommand();
      }

      cout<<stringToFind + " Now executing"<<endl;
      index += command->execute(index, lexerData);
      cout<<stringToFind + " Executed"<<endl;
    }
    VariableMap::setBool(true);
  } catch (const char *e) {
    std::cout << e << std::endl;
  }
}








