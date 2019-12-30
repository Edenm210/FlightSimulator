//
// Created by yakir on 12/30/19.
//

#ifndef EX3_PRINTCOMMAND_H
#define EX3_PRINTCOMMAND_H

#include <Command.h>
#include <string>

using namespace std;

class PrintCommand : public Command{

public:
    PrintCommand();
    ~PrintCommand();

    int execute(int i, vector<string> lexerData);
};


#endif //EX3_PRINTCOMMAND_H
