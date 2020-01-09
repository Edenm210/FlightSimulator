

#ifndef EX3_PRINTCOMMAND_H
#define EX3_PRINTCOMMAND_H

#include "Command.h"
#include <string>

using namespace std;

class PrintCommand : public Command {

public:
    PrintCommand();

    ~PrintCommand() override;

    int execute(int i, vector<string> lexerData) override;
};

#endif //EX3_PRINTCOMMAND_H
