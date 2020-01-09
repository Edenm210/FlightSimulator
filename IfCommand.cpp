

#include "IfCommand.h"
#include "Variable.h"
#include "Command.h"
#include <vector>
#include <list>
#include <unordered_map>
#include "CommandsMap.h"
#include "ConditionCommand.h"
#include "UpdateVarCommand.h"

using namespace std;

/* calling the father constructor.
the params is the number of steps to advance in the array after execute */
IfCommand::IfCommand() : ConditionCommand() {}

IfCommand::~IfCommand() {}

//trim the vector from the start after every execution / var definition
int IfCommand::execute(int i, vector<string> lexerData) {
    int j, k = 0, moveIndex = 0;// number of steps we will need to proceed in the lexerData after finishing the execute
    int savedI = i; // first index
    // advance from the token 'if' to the next token - the argument in the 'if' condition
    i++;
    string token = lexerData.at(i);
    ConditionCommand::initCondition(token); // initializing the condition Expressions on both sides+operator
    i++;
    token = lexerData[i]; //num of commands inside the "if" - as a string
    k = stoi(token); // number of commands inside the "if" - as an int
    i++; //the first command index in lexerData
    //checking if the condition is true
    if (ConditionCommand::conditionCheck()) {
        //k is number of commands to execute
        for (j = 0; j < k; j++) {
            token = lexerData[i]; // the commandName to execute
            unordered_map<string, Command *> commandMap = CommandsMap::getInstanceCommandMap()->getCommandMap();

            Command *command = CommandsMap::getInstanceCommandMap()->findCommandInMap(token); //getting the Command*

            //the command does not match so it is a variable name - updating variable value (=)
            if (command == NULL) {
                command = new UpdateVarCommand();
            }


            moveIndex = command->execute(i, lexerData);
            i += moveIndex; // moving to the next command in the loop
        }
    }
    this->numOfParams = i - savedI;
    return numOfParams;
}
