
#ifndef PROJECT3__VAR_H_
#define PROJECT3__VAR_H_

#include <string>
#include <unordered_map>
#include "Expression.h"

using namespace std;


class Var {

private:
    string sim; // var's simulator name
    string direct; // <- OR ->
    float val; // var's value

public:
    Var(string simName, string direction, float value);

    void changeVarValue(float newValue);

    float getVal();

    void setDirect(string str);

    string getDirect();

    string getSim();


};

#endif //PROJECT3__VAR_H_
