//
// Created by eden on 18/12/2019.
//

#include "CommandsMap.h"
#include "DefineVarCommand.h"
#include "OpenServerCommand.h"
#include "OpenClientCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "WhileCommand.h"
#include "IfCommand.h"

/* Null, because instance will be initialized on demand. */
CommandsMap* CommandsMap::instanceCommandMap = 0;

CommandsMap::CommandsMap() {
  //CONSTRUCTOR
  initCommandMap();
};


CommandsMap::~CommandsMap() {
  this->commandMap.clear();
  delete CommandsMap::instanceCommandMap;
}


CommandsMap* CommandsMap::getInstanceCommandMap() {
  if (instanceCommandMap == 0)
    instanceCommandMap = new CommandsMap;
  return instanceCommandMap;

}

unordered_map<string, Command*> CommandsMap::getCommandMap() {
  return this->commandMap;
}

void CommandsMap::initCommandMap() {
  this->commandMap["openDataServer"] = new OpenServerCommand();
  this->commandMap["connectControlClient"] = new OpenClientCommand();
  this->commandMap["var"] = new DefineVarCommand();
  this->commandMap["Print"] = new PrintCommand();
  this->commandMap["Sleep"] = new SleepCommand();
  this->commandMap["while"] = new WhileCommand();
  this->commandMap["if"] = new IfCommand();
}





