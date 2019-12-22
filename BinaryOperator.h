//
// Created by eden on 21/12/2019.
//

#ifndef PROJECT3__BINARYOPERATOR_H_
#define PROJECT3__BINARYOPERATOR_H_

#include "Expression.h"
class BinaryOperator : public Expression{

  // only the derived classes can access
 protected:
  Expression *left;
  Expression *right;

 public:
  BinaryOperator(Expression *leftExp, Expression *rightExp);
  virtual ~BinaryOperator(); // so the derived classes will be deleted as well
  // getters
  Expression *getLeft();
  Expression *getRight();

};


class Plus : public BinaryOperator {

 public:
  Plus(Expression *leftExp, Expression *rightExp);
  double calculate() override;

};

class Minus : public BinaryOperator {
 public:
  Minus(Expression *leftExp, Expression *rightExp);
  double calculate() override;
};

class Mul : public BinaryOperator {
 public:
  Mul(Expression *leftExp, Expression *rightExp);
  double calculate() override;
};

class Div : public BinaryOperator {
 public:
  Div(Expression *leftExp, Expression *rightExp);
  double calculate() override;
};



#endif //PROJECT3__BINARYOPERATOR_H_
