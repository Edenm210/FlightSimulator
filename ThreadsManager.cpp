

#include "ThreadsManager.h"

ThreadsManager *ThreadsManager::aThread = 0;

//returns an instance of the ThreadsManager class, if it doesnt exist - creates one
ThreadsManager *ThreadsManager::getThread() {
    if (!aThread) {
        aThread = new ThreadsManager;
    }
    return aThread;
}
