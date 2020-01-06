//
// Created by eden on 19/12/2019.
//

#include "Var.h"

Var::Var(string sim, string direct, float val) {
  this->sim = sim;
  this->direct = direct;
  this->val = val;
};

void Var::changeVarValue (float newValue) {
  this->val = newValue;
}

float Var::getVal () {
  return this->val;
}

string Var::getDirect () {
  return this->direct;
}

void Var::setDirect(string str){
    this->direct = direct;
}

string Var::getSim () {
  return this->sim;
}