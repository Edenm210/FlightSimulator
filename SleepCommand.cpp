

#include "SleepCommand.h"
#include <thread>
#include <iostream>

using namespace std;

SleepCommand::SleepCommand() {}

SleepCommand::~SleepCommand() {}

int SleepCommand::execute(int i, vector<string> lexerData) {
    int moveIndex = 0, time;
    string str;
    //advance the token 'Sleep' to the next token - the time to sleep
    i++;
    moveIndex++;

    str = lexerData[i];
    time = stoi(str);
    //if the time given is more than 1000 - convert it to seconds
    if (time > 1000) {
        time = time / 1000;
        this_thread::sleep_for(chrono::seconds(time));

    } else {
        this_thread::sleep_for(chrono::milliseconds(time));
    }

    moveIndex++;
    return moveIndex;
}



