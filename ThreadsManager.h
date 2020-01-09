
#ifndef EX3_THREADSMANAGER_H
#define EX3_THREADSMANAGER_H

#include <thread>

using namespace std;

class ThreadsManager {
private:
    ThreadsManager() {};
    static ThreadsManager *aThread;
public:
    static ThreadsManager *getThread();

    thread serverThread;
    thread clientThread;
};


#endif //EX3_THREADSMANAGER_H
