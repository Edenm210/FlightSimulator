//
// Created by yakir on 12/30/19.
//

#ifndef EX3_SLEEPCOMMAND_H
#define EX3_SLEEPCOMMAND_H

#include <Command.h>
#include <string>

class SleepCommand : public Command {

public:
    SleepCommand();
    ~SleepCommand();
    int execute(int i, vector<string> lexerData);
};


#endif //EX3_SLEEPCOMMAND_H
