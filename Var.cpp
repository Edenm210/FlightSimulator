//
// Created by eden on 19/12/2019.
//

#include "Var.h"

Var::Var(string sim, string genName, string direct, float val) {
  this->sim = sim;
  this->genName = genName;
  this->direct = direct;
  this->val = val;
};

void Var::updateVarValue (float newValue) {
  this->val = newValue;
}
