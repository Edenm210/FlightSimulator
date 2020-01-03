//
// Created by yakir on 12/22/19.
//

#ifndef EX3_OPENSERVERCOMMAND_H
#define EX3_OPENSERVERCOMMAND_H
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <vector>
#include "Command.h"

using namespace std;

class OpenServerCommand : public Command{
private:
  int portNum;
  int socketfd;
  sockaddr_in address;

 public:
    OpenServerCommand();
    ~OpenServerCommand() override;
    int runServer();
    int execute(int i, vector<string> lexerData) override;

};


#endif //EX3_OPENSERVERCOMMAND_H
