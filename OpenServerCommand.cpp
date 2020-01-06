//
// Created by yakir on 12/22/19.
//

#include "OpenServerCommand.h"
#include "lexer.h"
#include "VariableMap.h"
#include "thread"
#include "mutex"
#include "threadsManager.h"
#include "Interpreter.h"
#include "fstream"

///Mutex on connection action in server and client
///No need to mutex the map update


std::mutex mtxS;

OpenServerCommand::OpenServerCommand() {};

OpenServerCommand::~OpenServerCommand() {};

int OpenServerCommand::execute(int i, vector<string> lexerData) {
    int run, moveIndex = 0;
    auto inter1 = new Interpreter;
    i++;
    moveIndex++;
    this->portNum = (int) inter1->interpret(lexerData[i])->calculate();
    run = initServer();
    while (run != 0) {
        run = initServer();
    }
    threadsManager::getThread()->serverThread = thread(&OpenServerCommand::getData, this);
    threadsManager::getThread()->serverThread.detach();
    moveIndex++;
    return moveIndex;
}

int OpenServerCommand::initServer() {
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(portNum);

    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        return -2;
    }

    if (listen(socketfd, 5) == -1) {
        std::cerr << "Error during listening command" << std::endl;
        return -3;
    }
    cout << "Server is now listening..." << endl;
    // accept a client:
    client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
    if (client_socket == -1) {
        std::cerr << "Error accepting client" << std::endl;
        return -4;
    }
    cout << "Server Connected" << endl;
    ///Unlock the thread after connection with the simulator
    //mtxS.unlock();
    return 0;
}

void OpenServerCommand::getData() {
    int i, j = 0, genSize;
    float updatedVal = 0;
    auto inter1 = new Interpreter;
    string token = " ";
    string varName;
    //VariableMap* map = VariableMap::getInstanceVarsMap();
    //vector<string> varOrder = VariableMap::getVarNames();
    while (!VariableMap::getBool()) {
        //reading from client
        try {
            char buffer[2048] = {0};
            int valread = read(client_socket, buffer, 2048);
            //genSize = VariableMap::getInstanceVarsMap()->getGenVarsMap().size();
            //std::cout << buffer << std::endl;
            //f << buffer;
            //f.close();
            for (i = 0; i < 36; i++) {
                while (buffer[j] != '\n' && buffer[j] != ',' && buffer[j] != '\0') {
                    token.append(1, buffer[j]);
                    j++;
                }
                if (token != "\n" && token != "") {
                    updatedVal = (float) inter1->interpret(token)->calculate();
                    varName = VariableMap::getGenNames().at(i);
                    VariableMap::getInstanceVarsMap()->setVarValue(varName, updatedVal);
                }
                token.clear();
                memset(buffer, 0, sizeof(buffer));
                //std::cout<<"Server updating map..."<<endl;
                if (buffer[j] == ',' || buffer[j] == '\n') {
                    j++;
                }
            }
            ///Update between gen and fly map function here
            if (!VariableMap::getInstanceVarsMap()->getFlyVarsMap().empty()) {
                VariableMap::getInstanceVarsMap()->updateFlyFromGen();
            }
            //cout<<"Finished an update (Server)"<<endl;
            this_thread::sleep_for(chrono::milliseconds(100));
        } catch (exception e) {
            throw "Server messed up";
        }
    }
    close(socketfd); //closing the listening socket
}
