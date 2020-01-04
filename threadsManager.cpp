//
// Created by yakir on 1/1/20.
//

#include "threadsManager.h"

threadsManager* threadsManager::aThread = 0;

threadsManager *threadsManager::getThread() {
  if (!aThread) {
    aThread = new threadsManager;
  }
  return aThread;
}
