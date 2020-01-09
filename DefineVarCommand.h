

#ifndef PROJECT3__DEFINEVARCOMMAND_H_
#define PROJECT3__DEFINEVARCOMMAND_H_

#include <string>
#include "Command.h"
#include "vector"

using namespace std;

class DefineVarCommand : public Command {
public:
    DefineVarCommand();

    ~DefineVarCommand() override;

    int execute(int i, vector<string> lexerData) override; // i is the location of the commandName in the array



};

#endif //PROJECT3__DEFINEVARCOMMAND_H_
