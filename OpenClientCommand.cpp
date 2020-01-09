
#include <string>
#include <vector>
#include <cstring>
#include "OpenClientCommand.h"
#include "VariableMap.h"
#include "ThreadsManager.h"
#include "Interpreter.h"
#include "ConditionCommand.h"
#include <thread>


OpenClientCommand::OpenClientCommand() : Command() {}

OpenClientCommand::~OpenClientCommand() {}

int OpenClientCommand::execute(int i, vector<string> lexerData) {
    Interpreter *i1 = new Interpreter();
    Expression *exp = nullptr;

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
    //blocks until client is connected
    run = connectClient();
    while (run != 0) {
        run = connectClient();
    }
    //threading the client
    ThreadsManager::getThread()->clientThread = thread(&OpenClientCommand::runClient, this);
    ThreadsManager::getThread()->clientThread.detach();
    return numOfParams;
}

int OpenClientCommand::connectClient() {
    //create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
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
    int is_connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
    if (is_connect == -1) {
        std::cerr << "Could not connect to host server" << std::endl;
        return -2;
    } else {
        std::cout << "Client is now connected to server" << std::endl;
    }
    return 0;

}

void OpenClientCommand::runClient() {
    // running the client as long as the main thread lives (marked by a boolean)
    while (!VariableMap::getBool()) {
        string test;
        pair<string, float> tempVar;
        int i;
        //receives the updated vars (according to the script) in order to send to the client
        vector<pair<string, float>> updatedVars = VariableMap::getInstanceVarsMap()->getQueue();
        //if there are vars to send
        if (!updatedVars.empty()) {
            for (i = 0; i < updatedVars.size(); i++) {
                string sim = updatedVars[i].first;
                float val = updatedVars[i].second;
                string s = ("set " + sim + " " + to_string(val) + "\r\n");
                char cstr[s.size() + 1];
                strcpy(cstr, s.c_str());
                //sends the relevant "set" to the simulator
                send(client_socket, cstr, strlen(cstr), 0);
            }
        }
    }

    close(client_socket);
}
