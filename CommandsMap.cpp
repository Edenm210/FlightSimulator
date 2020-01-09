
#include "CommandsMap.h"
#include "DefineVarCommand.h"
#include "OpenServerCommand.h"
#include "OpenClientCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "WhileCommand.h"
#include "IfCommand.h"

/* Null, because instance will be initialized on demand. */
CommandsMap *CommandsMap::instanceCommandMap = 0;

CommandsMap::CommandsMap() {
    initCommandMap();
}


CommandsMap::~CommandsMap() {
    this->commandMap.clear();
    delete CommandsMap::instanceCommandMap;
}

//Finds the relevant command in map
Command *CommandsMap::findCommandInMap(string commandName) {
    auto it = this->commandMap.find(commandName);
    if (it != commandMap.end()) {
        return it->second;
    }
    return NULL;
}

//returns the class instance command map, if it doesnt exist - instantiate one
CommandsMap *CommandsMap::getInstanceCommandMap() {
    if (instanceCommandMap == 0)
        instanceCommandMap = new CommandsMap;
    return instanceCommandMap;

}

//returns the command map
unordered_map<string, Command *> CommandsMap::getCommandMap() {
    return this->commandMap;
}

//initializing the relevant commands (to be executed)
void CommandsMap::initCommandMap() {
    this->commandMap["openDataServer"] = new OpenServerCommand();
    this->commandMap["connectControlClient"] = new OpenClientCommand();
    this->commandMap["var"] = new DefineVarCommand();
    this->commandMap["Print"] = new PrintCommand();
    this->commandMap["Sleep"] = new SleepCommand();
    this->commandMap["while"] = new WhileCommand();
    this->commandMap["if"] = new IfCommand();
}





