

#include "Var.h"

Var::Var(string simName, string direction, float value) {
    this->sim = simName;
    this->direct = direction;
    this->val = value;
}

void Var::changeVarValue(float newValue) {
    this->val = newValue;
}


void Var::setDirect(string str) {
    this->direct = str;
}

float Var::getVal() {
    return this->val;
}

string Var::getDirect() {
    return this->direct;
}

string Var::getSim() {
    return this->sim;
}