//
// Created by eden on 19/12/2019.
//

#include "Var.h"

Var::Var(string sim, /*string name,*/ string direct, float val) {
  this->sim = sim;
  //this->name = name;
  this->direct = direct;
  this->val = val;
};

void Var::changeVarValue (float newValue) {
  this->val = newValue;
}
