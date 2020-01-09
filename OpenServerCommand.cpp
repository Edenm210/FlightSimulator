

#include "OpenServerCommand.h"
#include "VariableMap.h"
#include "thread"
#include "mutex"
#include "ThreadsManager.h"
#include "Interpreter.h"
#include "fstream"
#include "ConditionCommand.h"


OpenServerCommand::OpenServerCommand() {}

OpenServerCommand::~OpenServerCommand() {}

int OpenServerCommand::execute(int i, vector<string> lexerData) {
    int run, moveIndex = 0;
    auto inter1 = new Interpreter;
    i++;
    moveIndex++;
    this->portNum = (int) inter1->interpret(lexerData[i])->calculate();
    //blocks until server is connected
    run = initServer();
    while (run != 0) {
        run = initServer();
    }
    //threading the server
    ThreadsManager::getThread()->serverThread = thread(&OpenServerCommand::getData, this);
    ThreadsManager::getThread()->serverThread.detach();
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
    return 0;
}

void OpenServerCommand::getData() {
    int i, j = 0;
    float updatedVal = 0;
    auto inter1 = new Interpreter;
    string token = " ";
    string varName;
    string securityZero = "0";
    // running the server as long as the main thread lives (marked by a boolean)
    while (!VariableMap::getBool()) {
        char buffer[2048] = {0};
        //receives data from the simulator
        int valread = read(client_socket, buffer, 2048);
        // 36 - number of variables to be updated - tokenizing each value of each var
        for (i = 0; i < 36; i++) {
            while (buffer[j] != '\n' && buffer[j] != ',' && buffer[j] != '\0') {
                token.append(1, buffer[j]);
                j++;
            }
            if (token != "\n" && token != "" && token != "\0") {
                //getting the right var (by name) using a list to maintain the order
                varName = VariableMap::getInstanceVarsMap()->getGenName(i);
                //if server sends wrong data format - add zero to the beginning
                if (token[0] == '.') {
                    token.insert(0, securityZero);
                }
                updatedVal = (float) inter1->interpret(token)->calculate();
                //updating the value of a var
                VariableMap::getInstanceVarsMap()->setVarInGen(varName, updatedVal);
            }
            token.clear();
            if (buffer[j] == ',' || buffer[j] == '\n') {
                j++;
            }
        }
        memset(buffer, 0, sizeof(buffer));
        j = 0;
    }
    close(socketfd); //closing the listening socket
}
