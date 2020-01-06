//
// Created by yakir on 12/30/19.
//

#include "SleepCommand.h"
#include <thread>
#include <iostream>

using namespace std;

SleepCommand::SleepCommand() {}

SleepCommand::~SleepCommand() {}

int SleepCommand::execute(int i, vector<string> lexerData) {
  int moveIndex = 0, seconds, time;
  string str;
  //advance the token 'Sleep' to the next token - the time to sleep
  i++;
  moveIndex++;

  str = lexerData[i];
  time = stoi(str);
  if (time > 1000) {
    time = time / 1000;
    this_thread::sleep_for(chrono::seconds(time));

  } else {
    this_thread::sleep_for(chrono::milliseconds(time));
  }


  moveIndex++;
  cout << "Done Sleeping" << endl;

  return moveIndex;
}



