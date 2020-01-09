

#ifndef PROJECT3__COMMAND_H_
#define PROJECT3__COMMAND_H_

#include "Command.h"
#include <vector>
#include <thread>


using namespace std;


class Command {

public:
    int numOfParams = -1;

    virtual int execute(int i, vector<string> lexerData) = 0;

    virtual ~Command() {}

};


#endif //PROJECT3__COMMAND_H_
