//
// Created by eden on 19/12/2019.
//

#ifndef PROJECT3__VARIABLEMAP_H_
#define PROJECT3__VARIABLEMAP_H_

#include <string>
#include <unordered_map>
#include "Expression.h"
#include "Var.h"
#include <list>

using namespace std;


class VariableMap{

 private:
  static VariableMap* instanceVarMap;
  unordered_map<string, Var*> varsGenMap; // generic variables
  unordered_map<string, Var*> varsFlyMap; // variables from the "fly.txt" (from the code)

  static vector<string> VarGenNamesVec;
  static bool progEnd;

  /* Private constructor to prevent instancing. */
  VariableMap();
  void initVarMap();

 public:
  /* Static access method. */
  static VariableMap* getInstanceVarsMap();

  unordered_map<string, Var*> getGenVarsMap();
  unordered_map<string, Var*> getFlyVarsMap();

  void setVarValue(string name, float newValue);

  static vector<string> getVarNames();

  //void print();

  static bool getBool();

  static void setBool(bool b);

  ~VariableMap();

};

#endif //PROJECT3__VARIABLEMAP_H_
