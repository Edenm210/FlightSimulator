
#ifndef FINAL__UPDATEVARCOMMAND_H_
#define FINAL__UPDATEVARCOMMAND_H_

#include "Command.h"

class UpdateVarCommand : public Command {
public:
    UpdateVarCommand();

    ~UpdateVarCommand() override;

    int execute(int i, vector<string> lexerData) override; // i is the location of the commandName in the array

    void updateValueOfVar(string exp, string varName);


};

#endif //FINAL__UPDATEVARCOMMAND_H_
