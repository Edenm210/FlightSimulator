//
// Created by eden on 21/12/2019.
//

#include "BinaryOperator.h"


// BinaryOperator methods
Expression *BinaryOperator::getLeft() { return this->left; }
Expression *BinaryOperator::getRight() { return this->right; }
BinaryOperator::BinaryOperator(Expression *leftExp, Expression *rightExp) { this->left = leftExp, this->right = rightExp; }
BinaryOperator::~BinaryOperator() { delete this->left, delete this->right; }


Plus::Plus(Expression *leftExp, Expression *rightExp) : BinaryOperator(leftExp, rightExp) {}
double Plus::calculate() {
  return (this->getLeft()->calculate() + this->getRight()->calculate());
}

Minus::Minus(Expression *leftExp, Expression *rightExp) : BinaryOperator(leftExp, rightExp) {}
double Minus::calculate() {
  return (this->getLeft()->calculate() - this->getRight()->calculate());
}

Mul::Mul(Expression *leftExp, Expression *rightExp) : BinaryOperator(leftExp, rightExp) {}
double Mul::calculate() {
  return (this->getLeft()->calculate()*this->getRight()->calculate());
}

Div::Div(Expression *leftExp, Expression *rightExp) : BinaryOperator(leftExp, rightExp) {}
double Div::calculate() {
  if (this->getRight()->calculate()==0) { throw "can not divide by zero !"; }
  else { return (this->getLeft()->calculate()/this->getRight()->calculate()); }
}
