//
// Created by eden on 19/12/2019.
//

#ifndef PROJECT3__VAR_H_
#define PROJECT3__VAR_H_

#include <string>
#include <unordered_map>
#include "Expression.h"
using namespace std;

class Var {

 private:
  string sim;
  //string genName;
  string direct; // <- OR ->
  float val;

 public:
  Var(string sim,/* string genName,*/ string direct, float val);

  void updateVarValue (float newValue);

  float getVal();

  string getSim();

  string getDirect();


};




#endif //PROJECT3__VAR_H_
