

#ifndef PROJECT3__VARIABLEMAP_H_
#define PROJECT3__VARIABLEMAP_H_

#include <string>
#include <unordered_map>
#include "Expression.h"
#include "Var.h"
#include <vector>
#include "queue"

using namespace std;

class VariableMap {

private:
    static VariableMap *instanceVarMap;
    unordered_map<string, Var *> varsGenMap; // generic variables
    unordered_map<string, Var *> varsFlyMap; // variables from the "fly.txt" (from the code)
    static vector<string> varGenNames; // variables' gen-sim name list
    static bool progEnd; // a boolean that indicates to the server and client when to stop (threaded)
    static queue<pair<string, float>> *flyVarsQueue;// a queue to store the updated vars (for client)

    /* Private constructor to prevent instancing. */
    VariableMap();

    void initVarList();

public:
    /* Static access method. */
    static VariableMap *getInstanceVarsMap();

    unordered_map<string, Var *> getGenVarsMap();

    unordered_map<string, Var *> getFlyVarsMap();

    void setVarInGen(string name, float newValue);

    void setVarInFly(string name, float newValue);

    string getGenName(int i);

    vector<pair<string, float>> getQueue();

    void updateFlyFromGen();

    static bool getBool();

    void newValFlyMap(string name, string sign, float val);

    void updateVarsQueue(string name, float val);

    void clearUpdatedVars();

    void newVar(string sim, string direct, string name);

    float valByName(string s);

    Var *findSimInGen(string sim);

    Var *findSimInFly(string sim);

    static void setBool(bool b);

    ~VariableMap();

};

#endif //PROJECT3__VARIABLEMAP_H_