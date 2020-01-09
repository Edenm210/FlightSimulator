

#include "PrintCommand.h"
#include "VariableMap.h"
#include <iostream>

using namespace std;

int PrintCommand::execute(int i, vector<string> lexerData) {
    int moveIndex = 0;
    string str;
    float val = 0;
    //advance the token 'Print' to the next token - the data to print
    i++;
    moveIndex++;
    str = lexerData[i];
    // defines between a var's value or a string to print
    if (VariableMap::getInstanceVarsMap()->getFlyVarsMap().find(str) !=
        VariableMap::getInstanceVarsMap()->getFlyVarsMap().end()) {
        val = VariableMap::getInstanceVarsMap()->findSimInFly(str)->getVal();
        cout << val << endl;
    } else {
        cout << str << endl;
    }
    moveIndex++;
    this->numOfParams = moveIndex;
    return numOfParams;
}

PrintCommand::PrintCommand() : Command() {}

PrintCommand::~PrintCommand() {}
