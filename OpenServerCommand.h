//
// Created by yakir on 12/22/19.
//

#ifndef EX3_OpenServerCommand_H
#define EX3_OpenServerCommand_H
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <vector>
#include "Command.h"

using namespace std;

class OpenServerCommand : public Command {
 private:
  int portNum;
  int socketfd;
  int client_socket;
  sockaddr_in address;
 public:
  OpenServerCommand();
  ~OpenServerCommand();
  int initServer();
  void getData();
  int execute(int i, vector<string> lexerData);

};


#endif //EX3_OpenServerCommand_H