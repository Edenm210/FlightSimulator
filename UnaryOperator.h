//
// Created by eden on 21/12/2019.
//

#ifndef PROJECT3__UNARYOPERATOR_H_
#define PROJECT3__UNARYOPERATOR_H_

#include "Expression.h"
class UnaryOperator : public Expression{
 protected:
  Expression *unExp;

 public:
  UnaryOperator(Expression *exp);
  virtual ~UnaryOperator();
  // getter
  Expression *getUnExp();
};


class UPlus : public UnaryOperator {
 public:
  UPlus(Expression *exp);
  float calculate() override;

};

class UMinus : public UnaryOperator {
 public:
  UMinus(Expression *exp);
  float calculate() override;
};



#endif //PROJECT3__UNARYOPERATOR_H_
