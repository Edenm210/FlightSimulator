//
// Created by eden on 25/12/2019.
//

#include "Variable.h"

using namespace std;


//Variable class
Variable::Variable(string name, float value) { this->var_name = name, this->var_value = value; }
float Variable::calculate() { return this->var_value; }

Variable &Variable::operator++() {
  this->var_value++;
  return *this;
}

Variable &Variable::operator--() {
  this->var_value--;
  return *this;
}

Variable &Variable::operator+=(float num) {
  this->var_value += num;
  return *this;
}

Variable &Variable::operator-=(float num) {
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
