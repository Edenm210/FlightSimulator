//
// Created by eden on 17/12/2019.
//

#ifndef EX3__PARSER_H_
#define EX3__PARSER_H_

#include <map>
#include <unordered_map>
#include <vector>
#include "CommandsMap.h"
#include "VariableMap.h"

using namespace std;


class Parser {

 public:
  static void ParseCommand(vector<string> lexerData);

};

#endif //EX3__PARSER_H_
