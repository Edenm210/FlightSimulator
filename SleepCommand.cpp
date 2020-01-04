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
  //advance the token 'Print' to the next token - the data to print
  i++;
  moveIndex++;
  str = lexerData[i];
  time = stoi(str);
  chrono::milliseconds ms((int)time);
  this_thread::sleep_for(ms);
  moveIndex++;
  cout<<"Done Sleeping"<<endl;

  return moveIndex;
}



