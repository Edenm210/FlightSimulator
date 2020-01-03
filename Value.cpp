//
// Created by eden on 21/12/2019.
//

#include "Value.h"

//Value class
Value::Value(float val) : Expression() { this->value = val; } // calling the father constructor
float Value::calculate() { return this->value; }
float Value::getValue() const { return this->value; }