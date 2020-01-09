

#include <iostream>
#include "DefineVarCommand.h"
#include "VariableMap.h"
#include "Interpreter.h"
#include "ConditionCommand.h"
#include "mutex"

using namespace std;


DefineVarCommand::DefineVarCommand() : Command() {}

DefineVarCommand::~DefineVarCommand() {}

int DefineVarCommand::execute(int index,
                              vector<string> lexerData) { // i is the location of the commandName in the array

    string stringToFind = lexerData.at(index); // the word we want to find
    string name, direct;
    //name and direction (of updating) of the given var
    name = lexerData.at(index + 1);
    direct = lexerData.at(index + 2);
    if (direct.compare("=") != 0) {
        string sim = lexerData.at(index + 4);
        //inserting the new var to the maps
        VariableMap::getInstanceVarsMap()->newVar(sim, direct, name);
        this->numOfParams = 5;
    } else { // new 'stupid' variable - not pointing to any Var in the simulator only a value
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
            exp = i1->interpret(lexerData.at(index + 3));
            float newValue = exp->calculate();
            VariableMap::getInstanceVarsMap()->newValFlyMap(name, "=", newValue);
            this->numOfParams = 4;
        } catch (const char *e) {
            // Deleting a null pointer has no effect, so it is not necessary to check for a null pointer before calling delete.
            delete exp;
            delete i1;
            std::cout << e << std::endl;
        }

    }

    return this->numOfParams;

}