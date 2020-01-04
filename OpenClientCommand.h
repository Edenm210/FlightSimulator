//
// Created by eden on 31/12/2019.
//

#ifndef PROJECT3__OPENCLIENTCOMMAND_H_
#define PROJECT3__OPENCLIENTCOMMAND_H_

#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Command.h"

using namespace std;

class OpenClientCommand : public Command{
 private:
  int portNum;
  int client_socket;
  const char *ip;

//  int socketfd;
//  sockaddr_in address;
 public:
  OpenClientCommand();
  ~OpenClientCommand() override;
  int connectClient();
  static void runClient(int client_socket);

  int execute(int i, vector<string> lexerData) override;

};

#endif //PROJECT3__OPENCLIENTCOMMAND_H_