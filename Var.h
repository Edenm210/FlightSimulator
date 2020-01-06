//
// Created by eden on 19/12/2019.
//

#ifndef PROJECT3__VAR_H_
#define PROJECT3__VAR_H_

#include <string>
#include <unordered_map>
#include "Expression.h"
using namespace std;


class Var{

 private:
  string sim;
  string direct; // <- OR ->
  float val;

 public:
  Var(string sim, string direct, float val);

  void changeVarValue (float newValue);

  float getVal ();

  void setDirect(string str);

  string getDirect ();

  string getSim ();




};

#endif //PROJECT3__VAR_H_
