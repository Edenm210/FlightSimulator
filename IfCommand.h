//
// Created by eden on 21/12/2019.
//

#ifndef PROJECT3__IFCOMMAND_H_
#define PROJECT3__IFCOMMAND_H_

#include <string>
#include <vector>
#include "Command.h"
#include <unordered_map>
#include <Var.h>

using namespace std;

class IfCommand : public Command {

public:
    IfCommand(int params);

    virtual ~IfCommand() {}

    int execute(int i, vector<string> lexerData) override; // i is the location of the commandName in the array
    int idenOperator(string s);

    int idenOperator(char c);
    string varsToString(unordered_map<string, Var*> varMap);
    string getExp(string s);
};

#endif //PROJECT3__IFCOMMAND_H_
