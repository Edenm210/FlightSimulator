//
// Created by eden on 31/12/2019.
//

#include <string>
#include <vector>
#include <cstring>
#include "OpenClientCommand.h"
#include "VariableMap.h"
#include "threadsManager.h"
#include "Interpreter.h"
#include "ConditionCommand.h"
#include <thread>
#include <mutex>

std::mutex mtxC;

OpenClientCommand::OpenClientCommand():Command() {};
OpenClientCommand::~OpenClientCommand() {};

int OpenClientCommand::execute(int i, vector<string> lexerData) {
  Interpreter *i1 = new Interpreter();
  Expression *exp = nullptr;
  string varsToSet;
  //creating a string from the variables map, afterwards the Interpreter will use it
  unordered_map<string, Var *> varMap = VariableMap::getInstanceVarsMap()->getFlyVarsMap();
  if(!varMap.empty()) {
    varsToSet = ConditionCommand::varsToString(varMap);
    i1->setVariables(varsToSet);
  }

  try {
    exp = i1->interpret(lexerData[i + 2]);
    this->portNum = int(exp->calculate());
  } catch (const char *e) {
    // Deleting a null pointer has no effect, so it is not necessary to check for a null pointer before calling delete.
    delete exp;
    delete i1;
    std::cout << e << std::endl;
  }



  int run;
  this->numOfParams = 3;
  string ipString = lexerData.at(i + 1);
  const char *ipConst = ipString.c_str();

  this->ip = ipConst; //the ip Address

  run = connectClient();
  while (run != 0) {
    run = connectClient();
  }
  //threading the client
  threadsManager::getThread()->clientThread = thread (runClient, client_socket);
  threadsManager::getThread()->clientThread.detach();
  return numOfParams;
}

int OpenClientCommand::connectClient() {
  //create socket
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket==-1) {
    //error
    std::cerr << "Could not create a socket" << std::endl;
    return -1;
  }

  //We need to create a sockaddr obj to hold address of server
  sockaddr_in address; //in means IP4
  address.sin_family = AF_INET;//IP4
  address.sin_addr.s_addr = inet_addr(this->ip);  //the localhost address
  address.sin_port = htons(this->portNum);
  //we need to convert our number (both port & ip)
  // to a number that the network understands.

  // Requesting a connection with the server on the ip with the port
  ///Lock and wait for connection with the simulator
  //mtxC.lock();
  int is_connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
  if (is_connect==-1) {
    std::cerr << "Could not connect to host server" << std::endl;
    return -2;
  } else {
    std::cout << "Client is now connected to server" << std::endl;
  }
  ///Unlock the thread after connection with the simulator
  //mtxC.unlock();
  return 0;

}

void OpenClientCommand::runClient(int client_socket) {
  // running the program
  while (!VariableMap::getBool()) {
    //reading from client
    //char buffer[2048] = {0};
    //int valread = read(client_socket, buffer, 2048);
    // std::cout << buffer << std::endl;

    unordered_map<string, Var *> variablesMap = VariableMap::getInstanceVarsMap()->getFlyVarsMap();
    for(auto it=variablesMap.begin(); it!=variablesMap.end(); it++) { // going through the vars is the list
      if(it->second->getDirect() == "->") { //equals
        string sim = it->second->getSim();
        float val = it->second->getVal();
        string s = ("set "+ sim + " " + to_string(val) + "\r\n");
        char cstr[s.size() + 1];
        strcpy(cstr, s.c_str());

        //char* stringToSend = s;
        //cout<<"Client sending data..."<<endl;
        send(client_socket, cstr, strlen(cstr), 0);
      }
    }
    cout<<"Finished sending data (Client)"<<endl;
  }
  close(client_socket);

}
