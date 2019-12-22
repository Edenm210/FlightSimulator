//
// Created by eden on 21/12/2019.
//

#ifndef PROJECT3__VALUE_H_
#define PROJECT3__VALUE_H_

#include "Expression.h"
class Value : public Expression{

 private:
    double value;

   public:
    Value(double val);
    // Getter - can't change the value
    double getValue() const;
    double calculate() override;


};

#endif //PROJECT3__VALUE_H_
