
#include <iostream>
#include "UpdateVarCommand.h"
#include "Interpreter.h"
#include "VariableMap.h"
#include "ConditionCommand.h"

UpdateVarCommand::UpdateVarCommand() : Command() {
    this->numOfParams = 3;
}

UpdateVarCommand::~UpdateVarCommand() {}

int UpdateVarCommand::execute(int index,
                              vector<string> lexerData) { // i is the location of the commandName in the array

    string VarName = lexerData.at(index);
    string direct = lexerData.at(index + 1);
    // new 'stupid' variable - not pointing to any Var in the simulator only a value
    updateValueOfVar(lexerData.at(index + 2), VarName);
    return numOfParams;

}

void UpdateVarCommand::updateValueOfVar(string expression, string varName) {
    Interpreter *i1 = new Interpreter();
    Expression *exp = nullptr;
    string varsToSet;
    //creating a string from the variables map, afterwards the Interpreter will use it
    unordered_map<string, Var *> varMap;
    varMap = VariableMap::getInstanceVarsMap()->getFlyVarsMap();
    if (!varMap.empty()) {
        varsToSet = ConditionCommand::varsToString(varMap);
        i1->setVariables(varsToSet);
    }

    try {
        exp = i1->interpret(expression);
        float newValue = exp->calculate();
        if (VariableMap::getInstanceVarsMap()->findSimInFly(varName) != NULL) {
            VariableMap::getInstanceVarsMap()->setVarInFly(varName, newValue);
            VariableMap::getInstanceVarsMap()->updateVarsQueue(varName, newValue);
        } else {
            throw "var without initialization";
        }
    } catch (const char *e) {
        // Deleting a null pointer has no effect, so it is not necessary to check for a null pointer before calling delete.
        delete exp;
        delete i1;
        std::cout << e << std::endl;
    }
}