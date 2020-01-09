

#include <vector>
#include <iostream>
#include "VariableMap.h"
#include "mutex"

using namespace std;
//used to lock sensitive actions in the program, like creating and updating the maps.
mutex *mtx = new mutex;

//initializing static members of the class
VariableMap *VariableMap::instanceVarMap = 0;

bool VariableMap::progEnd = 1;

vector<string> VariableMap::varGenNames = {};

queue<pair<string, float>> *VariableMap::flyVarsQueue = new queue<pair<string, float>>;
//Constructor
VariableMap::VariableMap() {
    mtx->lock();
    //CONSTRUCTOR
    initVarList();
    mtx->unlock();
}
//adds a new var to the fly map (var that is not a part from the simulator)
void VariableMap::newValFlyMap(string name, string sign, float val) {
    mtx->lock();
    Var *v = new Var("", sign, val);
    varsFlyMap[name] = v;
    mtx->unlock();
}
//adds a new var to the maps
void VariableMap::newVar(string sim, string direct, string name) {
    mtx->lock();
    Var *v = new Var(sim, direct, 0);
    varsGenMap[sim] = v;
    varsFlyMap[name] = v;
    mtx->unlock();
}

//finds a var's simulator name in the fly map by name (from the script - ".txt")
Var *VariableMap::findSimInFly(string varName) {
    if (this->varsFlyMap.find(varName) != varsFlyMap.end()) {
        return this->varsFlyMap.at(varName);
    }
    return NULL;
}
//updating the queue with updated vars in order to send them later to the simulator via client
void VariableMap::updateVarsQueue(string name, float val) {
    if (varsFlyMap.find(name) != varsFlyMap.end()) {
        string simName = varsFlyMap[name]->getSim();
        auto p = make_pair(simName, val);
        flyVarsQueue->push(p);

    }
}

// Return a queue of the variables changed:
vector<pair<string, float>> VariableMap::getQueue() {
    vector<pair<string, float>> vec;
    while (!flyVarsQueue->empty()) {
        pair<string, float> p;
        p.first = flyVarsQueue->front().first;
        p.second = flyVarsQueue->front().second;
        vec.emplace_back(p);
        flyVarsQueue->pop();
    }
    return vec;
}

//destructor
VariableMap::~VariableMap() {
    this->varsGenMap.clear();
    this->varsFlyMap.clear();
    delete VariableMap::instanceVarMap;
}
//changing the value of a var through the Gen map
void VariableMap::setVarInGen(string sim, float newValue) {
    mtx->lock();
    if (varsGenMap.find(sim) != varsGenMap.end()) {
        varsGenMap.find(sim)->second->changeVarValue(newValue);
    }
    mtx->unlock();
}

//changing the value of a var through the Fly map
void VariableMap::setVarInFly(string name, float newValue) {
    mtx->lock();
    varsFlyMap[name]->changeVarValue(newValue);
    mtx->unlock();
}
//returns an instance of VariableMap class, if it doesnt exist - instantiate one
VariableMap *VariableMap::getInstanceVarsMap() {
    if (instanceVarMap == 0) {
        instanceVarMap = new VariableMap();
    }
    return instanceVarMap;
}
//return the Fly map
unordered_map<string, Var *> VariableMap::getFlyVarsMap() {
    return this->varsFlyMap;
}
//return the Gen map
unordered_map<string, Var *> VariableMap::getGenVarsMap() {
    return this->varsGenMap;
}
// return the name of a var at the 'i' place
string VariableMap::getGenName(int i) {
    return varGenNames[i];
}
//return the boolean that controls the server and client threads
bool VariableMap::getBool() {
    return VariableMap::progEnd;
}
//sets the boolean that control the server and client threads
void VariableMap::setBool(bool b) {
    VariableMap::progEnd = b;
}
//Initialize the simulator names in a vector in order to maintain the order of the vars
//when we update them from the server
void VariableMap::initVarList() {
    //"/instrumentation/airspeed-indicator/indicated-speed-kt"
    string simVar = "/instrumentation/airspeed-indicator/indicated-speed-kt";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/sim/time/warp"
    simVar = "/sim/time/warp";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/controls/switches/magnetos"
    simVar = "/controls/switches/magnetos";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/instrumentation/heading-indicator/offset-deg"
    simVar = "/instrumentation/heading-indicator/offset-deg";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/instrumentation/altimeter/indicated-altitude-ft"
    simVar = "/instrumentation/altimeter/indicated-altitude-ft";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/instrumentation/altimeter/pressure-alt-ft"
    simVar = "/instrumentation/altimeter/pressure-alt-ft";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/instrumentation/attitude-indicator/indicated-pitch-deg"
    simVar = "/instrumentation/attitude-indicator/indicated-pitch-deg";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/instrumentation/attitude-indicator/indicated-roll-deg"
    simVar = "/instrumentation/attitude-indicator/indicated-roll-deg";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/instrumentation/attitude-indicator/internal-pitch-deg"
    simVar = "/instrumentation/attitude-indicator/internal-pitch-deg";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/instrumentation/attitude-indicator/internal-roll-deg"
    simVar = "/instrumentation/attitude-indicator/internal-roll-deg";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/instrumentation/encoder/indicated-altitude-ft"
    simVar = "/instrumentation/encoder/indicated-altitude-ft";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/instrumentation/encoder/pressure-alt-ft"
    simVar = "/instrumentation/encoder/pressure-alt-ft";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/instrumentation/gps/indicated-altitude-ft"
    simVar = "/instrumentation/gps/indicated-altitude-ft";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/instrumentation/gps/indicated-ground-speed-kt"
    simVar = "/instrumentation/gps/indicated-ground-speed-kt";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/instrumentation/gps/indicated-vertical-speed"
    simVar = "/instrumentation/gps/indicated-vertical-speed";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/instrumentation/heading-indicator/indicated-heading-deg"
    simVar = "/instrumentation/heading-indicator/indicated-heading-deg";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/instrumentation/magnetic-compass/indicated-heading-deg"
    simVar = "/instrumentation/magnetic-compass/indicated-heading-deg";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/instrumentation/slip-skid-ball/indicated-slip-skid"
    simVar = "/instrumentation/slip-skid-ball/indicated-slip-skid";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/instrumentation/turn-indicator/indicated-turn-rate"
    simVar = "/instrumentation/turn-indicator/indicated-turn-rate";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/instrumentation/vertical-speed-indicator/indicated-speed-fpm"
    simVar = "/instrumentation/vertical-speed-indicator/indicated-speed-fpm";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/controls/flight/aileron"
    simVar = "/controls/flight/aileron";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/controls/flight/elevator"
    simVar = "/controls/flight/elevator";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/controls/flight/rudder"
    simVar = "/controls/flight/rudder";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/controls/flight/flaps"
    simVar = "/controls/flight/flaps";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/controls/engines/engine/throttle"
    simVar = "/controls/engines/engine/throttle";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/controls/engines/current-engine/throttle"
    simVar = "/controls/engines/current-engine/throttle";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/controls/switches/master-avionics"
    simVar = "/controls/switches/master-avionics";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/controls/switches/starter"
    simVar = "/controls/switches/starter";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/engines/active-engine/auto-start"
    simVar = "/engines/active-engine/auto-start";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/controls/flight/speedbrake"
    simVar = "/controls/flight/speedbrake";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/sim/model/c172p/brake-parking"
    simVar = "/sim/model/c172p/brake-parking";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/controls/engines/engine/primer"
    simVar = "/controls/engines/engine/primer";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/controls/engines/current-engine/mixture"
    simVar = "/controls/engines/current-engine/mixture";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/controls/switches/master-bat"
    simVar = "/controls/switches/master-bat";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/controls/switches/master-alt"
    simVar = "/controls/switches/master-alt";
    VariableMap::varGenNames.emplace_back(simVar);
    //"/engines/engine/rpm"
    simVar = "/engines/engine/rpm";
    VariableMap::varGenNames.emplace_back(simVar);
}

float VariableMap::valByName(string s) {
    auto it = this->varsFlyMap.find(s);
    if (it != varsFlyMap.end()) {
        return it->second->getVal();
    }
    return 0;
}

