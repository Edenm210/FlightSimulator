//
// Created by yakir on 12/30/19.
//

#include "SleepCommand.h"

SleepCommand::SleepCommand() {}

SleepCommand::~SleepCommand() {}

int SleepCommand::execute(int i, vector<string> lexerData) {
    int moveIndex = 0, seconds, miliseconds, time;
    string str;
    //advance the token 'Print' to the next token - the data to print
    i++;
    moveIndex++;
    str = lexerData[i];
    time = stoi(str);
    if (time > 1000) {
        seconds = time / 2500;
        miliseconds = time % 1000;
    }
    moveIndex++;
    //thread sleep

    return moveIndex;
}



