//
// Created by eden on 19/12/2019.
//

#include <vector>
#include <iostream>
#include "VariableMap.h"

using namespace std;


VariableMap* VariableMap::instanceVarMap = 0;

bool VariableMap::progEnd = 1;

vector<string> VariableMap::varGenNames = {};

queue<pair<string, float>> VariableMap::flyVarsQueue = {};

VariableMap::VariableMap() {
    //CONSTRUCTOR
    initVarMap();
};

void VariableMap::updateFlyMap(string name, Var* var){
    varsFlyMap[name] = var;
}


void VariableMap::updateVarsQueue(string name, float val) {
    auto temp = make_pair(name, val);
    flyVarsQueue.emplace(temp);
}

VariableMap::~VariableMap() {
    this->varsGenMap.clear();
    this->varsFlyMap.clear();
    delete VariableMap::instanceVarMap;
}

//void addVarToMap(string name, Var* v) {
//  VariableMap::getInstanceVarsMap()->getVarsMap()[name] = v; // adding the var to the map
//}

void VariableMap::setVarValue(string name, float newValue){
    //VariableMap::getInstanceVarsMap()->getGenVarsMap().find(name)->second->changeVarValue(newValue);
    varsGenMap[name]->changeVarValue(newValue);
}

VariableMap* VariableMap::getInstanceVarsMap() {
    if (instanceVarMap == 0) {
        instanceVarMap = new VariableMap();
    }
    return instanceVarMap;
}

unordered_map<string, Var*> VariableMap::getFlyVarsMap() {
    return this->varsFlyMap;
}

unordered_map<string, Var*> VariableMap::getGenVarsMap() {
    return this->varsGenMap;
}

vector<string> VariableMap::getGenNames() {
    return varGenNames;
}


bool VariableMap::getBool() {
    return VariableMap::progEnd;
}

void VariableMap::setBool(bool b) {
    VariableMap::progEnd = b;

}

void VariableMap::initVarMap() {
    //"/instrumentation/airspeed-indicator/indicated-speed-kt"
    string simVar = "/instrumentation/airspeed-indicator/indicated-speed-kt";
    Var *v1 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v1;

    //"/sim/time/warp"


    simVar = "/sim/time/warp";
    Var *v2 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v2;

    //"/controls/switches/magnetos"


    simVar = "/controls/switches/magnetos";
    Var *v3 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v3;

    //"/instrumentation/heading-indicator/offset-deg"


    simVar = "/instrumentation/heading-indicator/offset-deg";
    Var *v4 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v4;

    //"/instrumentation/altimeter/indicated-altitude-ft"


    simVar = "/instrumentation/altimeter/indicated-altitude-ft";
    Var *v5 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v5;

    //"/instrumentation/altimeter/pressure-alt-ft"


    simVar = "/instrumentation/altimeter/pressure-alt-ft";
    Var *v6 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v6;

    //"/instrumentation/attitude-indicator/indicated-pitch-deg"


    simVar = "/instrumentation/attitude-indicator/indicated-pitch-deg";
    Var *v7 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v7;

    //"/instrumentation/attitude-indicator/indicated-roll-deg"


    simVar = "/instrumentation/attitude-indicator/indicated-roll-deg";
    Var *v8 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v8;

    //"/instrumentation/attitude-indicator/internal-pitch-deg"


    simVar = "/instrumentation/attitude-indicator/internal-pitch-deg";
    Var *v9 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v9;

    //"/instrumentation/attitude-indicator/internal-roll-deg"


    simVar = "/instrumentation/attitude-indicator/internal-roll-deg";
    Var *v10 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v10;



    //"/instrumentation/encoder/indicated-altitude-ft"
    simVar = "/instrumentation/encoder/indicated-altitude-ft";
    Var *v11 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v11;

    //"/instrumentation/encoder/pressure-alt-ft"


    simVar = "/instrumentation/encoder/pressure-alt-ft";
    Var *v12 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v12;

    //"/instrumentation/gps/indicated-altitude-ft"


    simVar = "/instrumentation/gps/indicated-altitude-ft";
    Var *v13 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v13;



    //"/instrumentation/gps/indicated-ground-speed-kt"
    simVar = "/instrumentation/gps/indicated-ground-speed-kt";
    Var *v14 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v14;

    //"/instrumentation/gps/indicated-vertical-speed"


    simVar = "/instrumentation/gps/indicated-vertical-speed";
    Var *v15 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v15;

    //"/instrumentation/heading-indicator/indicated-heading-deg"


    simVar = "/instrumentation/heading-indicator/indicated-heading-deg";
    Var *v16 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v16;

    //"/instrumentation/magnetic-compass/indicated-heading-deg"


    simVar = "/instrumentation/magnetic-compass/indicated-heading-deg";
    Var *v17 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v17;

    //"/instrumentation/slip-skid-ball/indicated-slip-skid"


    simVar = "/instrumentation/slip-skid-ball/indicated-slip-skid";
    Var *v18 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v18;

    //"/instrumentation/turn-indicator/indicated-turn-rate"


    simVar = "/instrumentation/turn-indicator/indicated-turn-rate";
    Var *v19 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v19;

    //"/instrumentation/vertical-speed-indicator/indicated-speed-fpm"

    simVar = "/instrumentation/vertical-speed-indicator/indicated-speed-fpm";
    Var *v20 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);


    this->varsGenMap[simVar] = v20;

    //"/controls/flight/aileron"


    simVar = "/controls/flight/aileron";
    Var *v21 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v21;

    //"/controls/flight/elevator"


    simVar = "/controls/flight/elevator";
    Var *v22 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v22;

    //"/controls/flight/rudder"


    simVar = "/controls/flight/rudder";
    Var *v23 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v23;

    //"/controls/flight/flaps"


    simVar = "/controls/flight/flaps";
    Var *v24 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v24;

    //"/controls/engines/engine/throttle"
    simVar = "/controls/engines/engine/throttle";
    Var *v25 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);




    this->varsGenMap[simVar] = v25;

    //"/controls/engines/current-engine/throttle"
    simVar = "/controls/engines/current-engine/throttle";
    Var *v26 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);




    this->varsGenMap[simVar] = v26;

    //"/controls/switches/master-avionics"


    simVar = "/controls/switches/master-avionics";
    Var *v27 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v27;

    //"/controls/switches/starter"
    simVar = "/controls/switches/starter";
    Var *v28 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);
    this->varsGenMap[simVar] = v28;

    //"/engines/active-engine/auto-start"


    simVar = "/engines/active-engine/auto-start";
    Var *v29 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v29;

    //"/controls/flight/speedbrake"


    simVar = "/controls/flight/speedbrake";
    Var *v30 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v30;

    //"/sim/model/c172p/brake-parking"


    simVar = "/sim/model/c172p/brake-parking";
    Var *v31 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v31;

    //"/controls/engines/engine/primer"


    simVar = "/controls/engines/engine/primer";
    Var *v32 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);

    this->varsGenMap[simVar] = v32;

    //"/controls/engines/current-engine/mixture"


    simVar = "/controls/engines/current-engine/mixture";
    Var *v33 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);
    this->varsGenMap[simVar] = v33;

    //"/controls/switches/master-bat"
    simVar = "/controls/switches/master-bat";
    Var *v34 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);
    this->varsGenMap[simVar] = v34;

    //"/controls/switches/master-alt"
    simVar = "/controls/switches/master-alt";
    Var *v35 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);
    this->varsGenMap[simVar] = v35;

    //"/engines/engine/rpm"
    simVar = "/engines/engine/rpm";
    Var *v36 = new Var(simVar, "", 0);
    VariableMap::varGenNames.emplace_back(simVar);
    this->varsGenMap[simVar] = v36;

}

queue<pair<string, float>> VariableMap::getUpdatedVars() {
    return flyVarsQueue;
}

void VariableMap::updateFlyFromGen() {
    string name;
    float val;
    auto itFly = varsFlyMap.begin();
    while (itFly != varsFlyMap.end()) {
        name = itFly->second->getSim();
        if (varsGenMap.find(name) != varsGenMap.end()) {
            val = varsGenMap[name]->getVal();
            itFly->second->changeVarValue(val);
        }
        itFly++;
    }
}


/*
bool VariableMap::getFlyDone() {
    return doneFly;
}
void VariableMap::setFlyDone(bool c) {
    doneFly = c;
}
*/

/*
void VariableMap::print() {
    int i;
    string str;
    for (i = 0; i < VariableMap::varGenNames
  .size(); i++) {
        str = VariableMap::varGenNames
      .at(i);
        cout << this->varsGenMap.find(str)->first << ": " << this->varsGenMap.find(str)->second->getSim()
        << " - " << this->varsGenMap.find(str)->second->getDirect() << " - "
        << this->varsGenMap.find(str)->second->getVal() << endl;
        cout << VarNames.at(i) << endl;
    }
}
*/