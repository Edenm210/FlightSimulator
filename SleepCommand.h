//
// Created by yakir on 12/30/19.
//

#ifndef EX3_SLEEPCOMMAND_H
#define EX3_SLEEPCOMMAND_H

#include <string>
#include "Command.h"

class SleepCommand : public Command {

public:
  SleepCommand();
  ~SleepCommand() override;
  int execute(int i, vector<string> lexerData) override;
};


#endif //EX3_SLEEPCOMMAND_H
