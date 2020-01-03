//
// Created by yakir on 12/22/19.
//

#include "OpenServerCommand.h"
#include "lexer.h"
#include "VariableMap.h"

OpenServerCommand::OpenServerCommand():Command() {};
OpenServerCommand::~OpenServerCommand() {};

int OpenServerCommand::execute(int i, vector<string> lexerData) {
  i++;
  this->portNum = stoi(lexerData[i]);
  auto server = OpenServerCommand();
  //thread?
  server.runServer();
  this->numOfParams = 2;
  return numOfParams; // numOfParams
}

int OpenServerCommand::runServer() {
  int i, j = 0;
  float updatedVal;
  string token = " ";
  string varName;
  VariableMap *map = VariableMap::getInstanceVarsMap();
  vector<string> varOrder = VariableMap::getVarNames();
  //
  //create socket
  this->socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd==-1) {
    //error
    std::cerr << "Could not create a socket" << std::endl;
  }

  //bind socket to IP address
  // we first need to create the sockaddr obj.
  this->address = {}; //in means IP4
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
  address.sin_port = htons(portNum);
  //we need to convert our number
  // to a number that the network understands.

  //the actual bind command
  if (bind(socketfd, (struct sockaddr *) &address, sizeof(address))==-1) {
    std::cerr << "Could not bind the socket to an IP" << std::endl;
  }

  //making socket listen to the port
  if (listen(socketfd, 5)==-1) { //can also set to SOMAXCON (max connections)
    std::cerr << "Error during listening command" << std::endl;
  } else {
    std::cout << "Server is now listening ..." << std::endl;
  }

  // accepting a client
  sockaddr_in adder = this->address;
  int client_socket = accept(this->socketfd, (struct sockaddr *) &adder,
                             (socklen_t *) &adder);

  if (client_socket==-1) {
    std::cerr << "Error accepting client" << std::endl;
    return -4;
  }

  // running the program
  while (!VariableMap::getBool()) {
    //reading from client
    char buffer[2048] = {0};
    //reading from client
    int valread = read(client_socket, buffer, 2048);
    std::cout << buffer << std::endl; ///////////////////////////////////////////////////////////////////////////////////////
    for (i = 0; i < 36; i++) {
      while (buffer[j]!='\n' && buffer[j]!=',') {
        token.append(1, buffer[j]);
        j++;
      }
      updatedVal = stof(token);
      varName = varOrder[i];
      map->setVarValue(varName, updatedVal);
      token.clear();
      std::cout << updatedVal << endl;
      if (buffer[j]==',') {
        j++;
      }
    }
  }
  return 0;

  //close(socketfd); //closing the listening socket
}


