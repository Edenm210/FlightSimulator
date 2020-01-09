

#include <iostream>
#include <string>

#include "ConditionCommand.h"
#include "VariableMap.h"
#include "Interpreter.h"

ConditionCommand::ConditionCommand() {
}

// identifies an operator (one char)
int ConditionCommand::idenOperator(char c) {
    switch (c) {
        case '<':
            return 1;
        case '>':
            return 2;
        case '=':
            return 20;
        default:
            return 0;
    }
}

// identifies an operator (two chars)
int ConditionCommand::idenOperator(string s) {
    if (s == "==") {
        return 3;
    } else if (s == "<=") {
        return 4;
    } else if (s == ">=") {
        return 5;
    } else if (s == "!=") {
        return 6;
    } else {
        return 0;
    }
}

// creating a variables string in the form the Interpreter works with
string ConditionCommand::varsToString(unordered_map<string, Var *> varMap) {
    string s;
    for (auto &it: varMap) {
        s.append(it.first);
        s.append("=");
        s.append(to_string(it.second->getVal()));
        s.append(";");
    }
    s.pop_back();
    return s;
}

void ConditionCommand::initCondition(string token) {
    int k = 0;
    char ch;
    string varsToSet, exp1, exp2, sign;

    unordered_map<string, Var *> varMap = VariableMap::getInstanceVarsMap()->getFlyVarsMap();

    auto *i1 = new Interpreter();
    Expression *e1 = nullptr;
    Expression *e2 = nullptr;
    varsToSet = varsToString(varMap);
    i1->setVariables(varsToSet);

    // Calculate the expressions and sign of if or while condition
    while (!idenOperator(token[k])) {
        exp1.append(1, token[k]);
        k++;
    }
    //calculate the left expression of the token
    e1 = i1->interpret(exp1);
    this->leftArg = e1->calculate();
    //check the operator
    if (idenOperator(token[k + 1])) {
        sign.append(1, token[k]); // adding it to the sign string
        sign.append(1, token[k + 1]);
        this->oper = idenOperator(sign);
        k += 2;
    } else {
        ch = token[k];
        this->oper = idenOperator(ch);
        k++;
    }
    while (k < token.size()) {
        exp2.append(1, token[k]);
        k++;
    }
    //calculate the right expression of the token
    e2 = i1->interpret(exp2);
    this->rightArg = e2->calculate();
}

//checks if the condition of if or while command is viable
bool ConditionCommand::conditionCheck() {
    switch (this->oper) {
        // <
        case 1:
            if (this->leftArg < this->rightArg) {
                return true;
            }
            return false;
            // >
        case 2:
            if (this->leftArg > this->rightArg) {
                return true;
            }
            return false;
            // ==
        case 3:
            if (this->leftArg == this->rightArg) {
                return true;
            }
            return false;
            // <=
        case 4:
            if (this->leftArg <= this->rightArg) {
                return true;
            }
            return false;
            // >=
        case 5:
            if (this->leftArg >= this->rightArg) {
                return true;
            }
            return false;
            // !=
        case 6:
            if (this->leftArg != this->rightArg) {
                return true;
            }
            return false;
        default:
            break;
    }
    return false;
}
