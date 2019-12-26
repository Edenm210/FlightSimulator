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
  unordered_map<string, Var*> varsMap; // varsName and its sim+value
  list<string> VarNames;

  /* Private constructor to prevent instancing. */
  VariableMap();
  void initVarMap();


 public:
  /* Static access method. */
  static VariableMap* getInstanceVarsMap();

  unordered_map<string, Var*> getVarsMap();

  void setVarValue(string name, float newValue);



  ~VariableMap();

};




#endif //PROJECT3__VARIABLEMAP_H_
