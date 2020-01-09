

#include <string>
#include "WhileCommand.h"
#include "vector"
#include "CommandsMap.h"
#include "DefineVarCommand.h"
#include <unordered_map>
#include "UpdateVarCommand.h"

using namespace std;

/* calling the father constructor.
the params is the number of steps to advance in the array after execute */
WhileCommand::WhileCommand() : ConditionCommand() {}

WhileCommand::~WhileCommand() {}

int WhileCommand::execute(int i, vector<string> lexerData) {
    int numOfCommandsInWhile = stoi(lexerData.at(i + 2)); // number of commands inside the "while"
    // advance from the token 'while' to the next token - the expression
    string token = lexerData.at(i + 1);
    ConditionCommand::initCondition(token); // initializing the condition Expressions on both sides+operator

    /// END OF Calculate the expressions and sign of 'while' condition
    // int lastCom;
    int firstIndex = i; //the "while" word
    int firstCommand = i + 3; // saving the index of the first command so we can go back to it in every iteration
    int comToExecute = firstCommand;

    //while the condition is true
    while (ConditionCommand::conditionCheck()) {
        comToExecute = firstCommand;
        //i=firstCommand;

        // executing all the commands in the loop
        for (int j = 1; j <= numOfCommandsInWhile; j++) {
            string comName = lexerData[comToExecute]; // the commandName to execute
            unordered_map<string, Command *> commandMap = CommandsMap::getInstanceCommandMap()->getCommandMap();
            Command *command = CommandsMap::getInstanceCommandMap()->findCommandInMap(comName); //getting the VAR*

            if (command == NULL) {
                command = new UpdateVarCommand();
            }

            //int h = command->numOfParams;

            int h = command->execute(comToExecute, lexerData);
            comToExecute += h; // moving to the next command in the loop
        }
        ConditionCommand::initCondition(
                lexerData.at((firstIndex + 1))); // initializing the condition Expressions on both sides+operator

    }
    this->numOfParams = comToExecute - (firstIndex);
    return numOfParams;

}







