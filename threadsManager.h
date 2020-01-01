//
// Created by yakir on 1/1/20.
//

#ifndef EX3_THREADSMANAGER_H
#define EX3_THREADSMANAGER_H

#include <thread>

using namespace std;

class threadsManager {
private:
threadsManager(){};
static threadsManager* aThread;
public:
    static threadsManager* getThread();
    thread serverThread;
    thread clientThread;
};


#endif //EX3_THREADSMANAGER_H
