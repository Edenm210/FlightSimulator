//
// Created by eden on 21/12/2019.
//

#include "UnaryOperator.h"
// UnaryOperator methods
UnaryOperator::UnaryOperator(Expression *exp) { this->unExp = exp; }
UnaryOperator::~UnaryOperator() { delete this->unExp; }
Expression *UnaryOperator::getUnExp() { return this->unExp; }


UPlus::UPlus(Expression *exp) : UnaryOperator(exp) {}
double UPlus::calculate() {
  return this->getUnExp()->calculate();
}

UMinus::UMinus(Expression *exp) : UnaryOperator(exp) {}
double UMinus::calculate() {
  return this->getUnExp()->calculate()*(-1);
}