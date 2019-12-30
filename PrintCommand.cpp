//
// Created by yakir on 12/30/19.
//

#include "PrintCommand.h"
#include <VariableMap.h>
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
    if(VariableMap::getInstanceVarsMap()->getVarsMap().find(str) !=
    VariableMap::getInstanceVarsMap()->getVarsMap().end()) {
       val = VariableMap::getInstanceVarsMap()->getVarsMap().at(str)->getVal();
       cout<<val<<endl;
    } else {
        cout<<str<<endl;
    }
    moveIndex++;
    i++;
    return moveIndex;
}

PrintCommand::PrintCommand() {}

PrintCommand::~PrintCommand() {}
