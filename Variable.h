//
// Created by eden on 25/12/2019.
//

#ifndef PROJECT3__VARIABLE_H_
#define PROJECT3__VARIABLE_H_

#include <string>
#include "Expression.h"
class Variable : public Expression {
 private:
  string var_name;
  float var_value;

 public:
  Variable(string name, float value);
  float calculate() override;

  Variable &operator++();
  Variable &operator--();
  Variable &operator+=(float num);
  Variable &operator-=(float num);
  Variable &operator++(int);
  Variable &operator--(int);
};

#endif //PROJECT3__VARIABLE_H_
