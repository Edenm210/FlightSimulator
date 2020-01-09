

#ifndef EX3__COMMAND_H_
#define EX3__COMMAND_H_

using namespace std;
/**
 * Command Interface
 */


#include <unordered_map>
#include "Command.h"

class CommandsMap {

 private:
  static CommandsMap* instanceCommandMap;
  unordered_map<string, Command*> commandMap; // commands Map

  /* Private constructor to prevent instancing. */
  CommandsMap();
  void initCommandMap();



 public:
  /* Static access method. */
  static CommandsMap* getInstanceCommandMap();

  unordered_map<string, Command*> getCommandMap();

  Command* findCommandInMap(string commandName);



    ~CommandsMap();

};

#endif //EX3__COMMAND_H_
