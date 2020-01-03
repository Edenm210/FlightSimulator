//
// Created by eden on 21/12/2019.
//

#ifndef PROJECT3__VALUE_H_
#define PROJECT3__VALUE_H_

#include "Expression.h"
class Value : public Expression {

 private:
  float value;

 public:
  explicit Value(float val);
  // Getter - can't change the value
  float getValue() const;
  float calculate() override;

};

#endif //PROJECT3__VALUE_H_
