//
// Created by eden on 19/12/2019.
//

#ifndef PROJECT3__VARIABLEMAP_H_
#define PROJECT3__VARIABLEMAP_H_

#include <string>
#include <unordered_map>
#include "Expression.h"
#include "Var.h"
#include <vector>
#include "queue"

using namespace std;

class VariableMap {

 private:
  static VariableMap *instanceVarMap;
  unordered_map<string, Var *> varsGenMap; // generic variables
  unordered_map<string, Var *> varsFlyMap; // variables from the "fly.txt" (from the code)
  static vector<string> varGenNames; // variables' gen-sim name list
  static queue<pair<string, float>> flyVarsQueue;
  static bool progEnd;

  /* Private constructor to prevent instancing. */
  VariableMap();
  void initVarMap();

 public:
  /* Static access method. */
  static VariableMap *getInstanceVarsMap();

  unordered_map<string, Var *> getGenVarsMap();
  unordered_map<string, Var *> getFlyVarsMap();

  void setVarValue(string name, float newValue);

  static string getGenName(int i);

  static queue<pair<string, float>> getUpdatedVars();

  void updateFlyFromGen();

  //void print();

  static bool getBool();

  void updateFlyMap(string name, Var *var);

  void updateVarsQueue(string name, float val);

  void clearUpdatedVars();

  Var *findSimInGen(string sim);

  static void setBool(bool b);

  ~VariableMap();

};

#endif //PROJECT3__VARIABLEMAP_H_