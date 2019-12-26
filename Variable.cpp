//
// Created by eden on 25/12/2019.
//

#include "Variable.h"

//Variable class
Variable::Variable(string name, double value) { this->var_name = name, this->var_value = value; }
double Variable::calculate() { return this->var_value; }

Variable &Variable::operator++() {
  this->var_value++;
  return *this;
}

Variable &Variable::operator--() {
  this->var_value--;
  return *this;
}

Variable &Variable::operator+=(double num) {
  this->var_value += num;
  return *this;
}

Variable &Variable::operator-=(double num) {
  this->var_value -= num;
  return *this;
}

Variable &Variable::operator++(int) {
  this->var_value++;
  return *this;
}

Variable &Variable::operator--(int) {
  this->var_value--;
  return *this;
}
