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
  time = time /100;
  chrono::milliseconds ms(0);
  chrono::seconds sec(time);
  this_thread::__sleep_for(sec ,ms);
  moveIndex++;
  cout<<"Done Sleeping"<<endl;

  return moveIndex;
}



