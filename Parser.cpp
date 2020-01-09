

#include <iostream>
#include "Parser.h"
#include "CommandsMap.h"
#include <vector>
#include "DefineVarCommand.h"
#include "VariableMap.h"
#include "UpdateVarCommand.h"

using namespace std;

void Parser::ParseCommand(vector<string> lexerData) {
    try {
        unordered_map<string, Command *> commandMap = CommandsMap::getInstanceCommandMap()->getCommandMap();

        int index = 0, sleep = 15;
        int size = lexerData.size();
        while (index < size) {
            string stringToFind = lexerData.at(index); // the word we want to find
            //indicates that lexerData is finished
            if (stringToFind == "EndOfProgram - Airplane is airborne") {
                //marks the client and server to end their run
                VariableMap::setBool(true);
                //waiting 15 seconds to make sure client and server stopped running
                this_thread::sleep_for(chrono::seconds (sleep));
                return;
            }
            Command *command = CommandsMap::getInstanceCommandMap()->findCommandInMap(stringToFind); //getting the VAR*

            //the command does not match so it is a variable name - updating variable value (=)
            if (command == NULL) {
                command = new UpdateVarCommand();
            }

            index += command->execute(index, lexerData);
        }
    } catch (const char *e) {
        std::cout << e << std::endl;
    }
}








