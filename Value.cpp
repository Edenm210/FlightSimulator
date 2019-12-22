//
// Created by eden on 21/12/2019.
//

#include "Value.h"

//Value class
Value::Value(double val) : Expression() { this->value = val; } // calling the father constructor
double Value::calculate() { return this->value; }
double Value::getValue() const { return this->value; }