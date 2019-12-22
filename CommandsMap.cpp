//
// Created by eden on 18/12/2019.
//

#include "CommandsMap.h"

/* Null, because instance will be initialized on demand. */
CommandsMap* CommandsMap::instanceCommandMap = 0;

CommandsMap::CommandsMap() {
 ////////////CONSTRUCTOR
};


CommandsMap::~CommandsMap() {this->commandMap.clear();}


CommandsMap* CommandsMap::getInstanceCommandMap() {
  if (instanceCommandMap == 0)
    instanceCommandMap = new CommandsMap;
  return instanceCommandMap;

}

unordered_map<string, Command> CommandsMap::getCommandMap() {
  return this->commandMap;
}





