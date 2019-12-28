//
// Created by eden on 19/12/2019.
//

#include <vector>
#include <iostream>
#include "VariableMap.h"

VariableMap* VariableMap::instanceVarMap = 0;


VariableMap::VariableMap() {
  //CONSTRUCTOR
  initVarMap();
};


VariableMap::~VariableMap() {
  this->varsGenMap.clear();
  this->varsFlyMap.clear();
}

//void addVarToMap(string name, Var* v) {
//  VariableMap::getInstanceVarsMap()->getVarsMap()[name] = v; // adding the var to the map
//}

void VariableMap::setVarValue(string name, float newValue){
  VariableMap::getInstanceVarsMap()->getGenVarsMap().find(name)->second->changeVarValue(newValue);
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

void VariableMap::initVarMap() {
  string simVar = "/instrumentation/airspeed-indicator/indicated-speed-kt";
  Var *v1 = new Var("/instrumentation/airspeed-indicator/indicated-speed-kt", /*"airspeed-indicator_indicated-speed-kt",*/ "", 0);
//  v1->genName = "airspeed-indicator_indicated-speed-kt";
//  v1->sim = "/instrumentation/airspeed-indicator/indicated-speed-kt";
//  v1->val = 0;
//  v1->direct = "";
  this->VarGenNames.emplace_back("airspeed-indicator_indicated-speed-kt");
  this->varsGenMap[simVar] = v1;

//  varName = "time_warp";
//  Var::Var *v2 = new Var::Var;
//  v2->genName = "time_warp";
//  v2->sim = "/sim/time/warp";
//  v2->val = 0;
//  v2->direct = "";
//  this->VarGenNames.emplace_back("time_warp");
//  this->varsGenMap[varName] = v2;
//
//  varName = "switches_magnetos";
//  Var::Var *v3 = new Var::Var;
//  v3->genName = "switches_magnetos";
//  v3->sim = "/controls/switches/magnetos";
//  v3->val = 0;
//  v3->direct = "";
//  this->VarGenNames.emplace_back("switches_magnetos");
//  this->varsGenMap[varName] = v3;
//
//  varName = "heading-indicator_offset-deg";
//  Var::Var *v4 = new Var::Var;
//  v4->genName = "heading-indicator_offset-deg";
//  v4->sim = "/instrumentation/heading-indicator/offset-deg";
//  v4->val = 0;
//  v4->direct = "";
//  this->VarGenNames.emplace_back("heading-indicator_offset-deg");
//  this->varsGenMap[varName] = v4;
//
//  varName = "altimeter_indicated-altitude-ft";
//  Var::Var *v5 = new Var::Var;
//  v5->genName = "altimeter_indicated-altitude-ft";
//  v5->sim = "/instrumentation/altimeter/indicated-altitude-ft";
//  v5->val = 0;
//  v5->direct = "";
//  this->VarGenNames.emplace_back("altimeter_indicated-altitude-ft");
//  this->varsGenMap[varName] = v5;
//
//  varName = "altimeter_pressure-alt-ft";
//  Var::Var *v6 = new Var::Var;
//  v6->genName = "altimeter_pressure-alt-ft";
//  v6->sim = "//instrumentation/altimeter/pressure-alt-ft";
//  v6->val = 0;
//  v6->direct = "";
//  this->VarGenNames.emplace_back("altimeter_pressure-alt-ft");
//  this->varsGenMap[varName] = v6;
//
//  varName = "attitude-indicator_indicated-pitch-deg";
//  Var::Var *v7 = new Var::Var;
//  v7->genName = "attitude-indicator_indicated-pitch-deg";
//  v7->sim = "/instrumentation/attitude-indicator/indicated-pitch-deg";
//  v7->val = 0;
//  v7->direct = "";
//  this->VarGenNames.emplace_back("attitude-indicator_indicated-pitch-deg");
//  this->varsGenMap[varName] = v7;
//
//  varName = "attitude-indicator_indicated-roll-deg";
//  Var::Var *v8 = new Var::Var;
//  v8->genName = "attitude-indicator_indicated-roll-deg";
//  v8->sim = "/instrumentation/attitude-indicator/indicated-roll-deg";
//  v8->val = 0;
//  v8->direct = "";
//  this->VarGenNames.emplace_back("attitude-indicator_indicated-roll-deg");
//  this->varsGenMap[varName] = v8;
//
//  varName = "attitude-indicator_internal-pitch-deg";
//  Var::Var *v9 = new Var::Var;
//  v9->genName = "attitude-indicator_internal-pitch-deg";
//  v9->sim = "/instrumentation/attitude-indicator/internal-pitch-deg";
//  v9->val = 0;
//  v9->direct = "";
//  this->VarGenNames.emplace_back("attitude-indicator_internal-pitch-deg");
//  this->varsGenMap[varName] = v9;
//
//  varName = "attitude-indicator_internal-roll-deg";
//  Var::Var *v10 = new Var::Var;
//  v10->genName = "attitude-indicator_internal-roll-deg";
//  v10->sim = "/instrumentation/attitude-indicator/internal-roll-deg";
//  v10->val = 0;
//  v10->direct = "";
//  this->VarGenNames.emplace_back("attitude-indicator_internal-roll-deg");
//  this->varsGenMap[varName] = v10;
//
//  varName = "encoder_indicated-altitude-ft";
//  Var::Var *v11 = new Var::Var;
//  v11->genName = "encoder_indicated-altitude-ft";
//  v11->sim = "/instrumentation/encoder/indicated-altitude-ft";
//  v11->val = 0;
//  v11->direct = "";
//  this->VarGenNames.emplace_back("encoder_indicated-altitude-ft");
//  this->varsGenMap[varName] = v11;
//
//  varName = "encoder_pressure-alt-ft";
//  Var::Var *v12 = new Var::Var;
//  v12->genName = "encoder_pressure-alt-ft";
//  v12->sim = "/instrumentation/encoder/pressure-alt-ft";
//  v12->val = 0;
//  v12->direct = "";
//  this->VarGenNames.emplace_back("encoder_pressure-alt-ft");
//  this->varsGenMap[varName] = v12;
//
//  varName = "gps_indicated-altitude-ft";
//  Var::Var *v13 = new Var::Var;
//  v13->genName = "gps_indicated-altitude-ft";
//  v13->sim = "/instrumentation/gps/indicated-altitude-ft";
//  v13->val = 0;
//  v13->direct = "";
//  this->VarGenNames.emplace_back("gps_indicated-altitude-ft");
//  this->varsGenMap[varName] = v13;
//
//  varName = "gps_indicated-ground-speed-kt";
//  Var::Var *v14 = new Var::Var;
//  v14->genName = "gps_indicated-ground-speed-kt";
//  v14->sim = "/instrumentation/gps/indicated-ground-speed-kt";
//  v14->val = 0;
//  v14->direct = "";
//  this->VarGenNames.emplace_back("gps_indicated-ground-speed-kt");
//  this->varsGenMap[varName] = v14;
//
//  varName = "gps_indicated-vertical-speed";
//  Var::Var *v15 = new Var::Var;
//  v15->genName = "gps_indicated-vertical-speed";
//  v15->sim = "/instrumentation/gps/indicated-vertical-speed";
//  v15->val = 0;
//  v15->direct = "";
//  this->VarGenNames.emplace_back("gps_indicated-vertical-speed");
//  this->varsGenMap[varName] = v15;
//
//  varName = "indicated-heading-deg";
//  Var::Var *v16 = new Var::Var;
//  v16->genName = "indicated-heading-deg";
//  v16->sim = "/instrumentation/heading-indicator/indicated-heading-deg";
//  v16->val = 0;
//  v16->direct = "";
//  this->VarGenNames.emplace_back("indicated-heading-deg");
//  this->varsGenMap[varName] = v16;
//
//  varName = "magnetic-compass_indicated-heading-deg";
//  Var::Var *v17 = new Var::Var;
//  v17->genName = "magnetic-compass_indicated-heading-deg";
//  v17->sim = "/instrumentation/magnetic-compass/indicated-heading-deg";
//  v17->val = 0;
//  v17->direct = "";
//  this->VarGenNames.emplace_back("magnetic-compass_indicated-heading-deg");
//  this->varsGenMap[varName] = v17;
//
//  varName = "lip-skid-ball_indicated-slip-skid";
//  Var::Var *v18 = new Var::Var;
//  v18->genName = "lip-skid-ball_indicated-slip-skid";
//  v18->sim = "/instrumentation/slip-skid-ball/indicated-slip-skid";
//  v18->val = 0;
//  v18->direct = "";
//  this->VarGenNames.emplace_back("lip-skid-ball_indicated-slip-skid");
//  this->varsGenMap[varName] = v18;
//
//  varName = "turn-indicator_indicated-turn-rate";
//  Var::Var *v19 = new Var::Var;
//  v19->genName = "turn-indicator_indicated-turn-rate";
//  v19->sim = "/instrumentation/turn-indicator/indicated-turn-rate";
//  v19->val = 0;
//  v19->direct = "";
//  this->VarGenNames.emplace_back("turn-indicator_indicated-turn-rate");
//  this->varsGenMap[varName] = v19;
//
//  varName = "vertical-speed-indicator_indicated-speed-fpm";
//  Var::Var *v20 = new Var::Var;
//  v20->genName = "vertical-speed-indicator_indicated-speed-fpm";
//  v20->sim = "vertical-speed-indicator_indicated-speed-fpm";
//  v20->val = 0;
//  v20->direct = "";
//  this->VarGenNames.emplace_back("vertical-speed-indicator_indicated-speed-fpm");
//  this->varsGenMap[varName] = v20;
//
//  varName = "flight_aileron";
//  Var::Var *v21 = new Var::Var;
//  v21->genName = "flight_aileron";
//  v21->sim = "/controls/flight/aileron";
//  v21->val = 0;
//  v21->direct = "";
//  this->VarGenNames.emplace_back("flight_aileron");
//  this->varsGenMap[varName] = v21;
//
//  varName = "flight_elevator";
//  Var::Var *v22 = new Var::Var;
//  v22->genName = "flight_elevator";
//  v22->sim = "/controls/flight/elevator";
//  v22->val = 0;
//  v22->direct = "";
//  this->VarGenNames.emplace_back("flight_elevator");
//  this->varsGenMap[varName] = v22;
//
//  varName = "flight_rudder";
//  Var::Var *v23 = new Var::Var;
//  v23->genName = "flight_rudder";
//  v23->sim = "/controls/flight/rudder";
//  v23->val = 0;
//  v23->direct = "";
//  this->VarGenNames.emplace_back("flight_rudder");
//  this->varsGenMap[varName] = v23;
//
//  varName = "flight_flaps";
//  Var::Var *v24 = new Var::Var;
//  v24->genName = "flight_flaps";
//  v24->sim = "/controls/flight/flaps";
//  v24->val = 0;
//  v24->direct = "";
//  this->VarGenNames.emplace_back("flight_flaps");
//  this->varsGenMap[varName] = v24;
//
  simVar = "/controls/engines/engine/throttle";
  Var *v25 = new Var("/controls/engines/engine/throttle", /*"engine_throttle",*/ "", 0 );
//  v25->genName = "engine_throttle";
//  v25->sim = "/controls/engines/engine/throttle";
//  v25->val = 0;
//  v25->direct = "";
  this->VarGenNames.emplace_back("engine_throttle");
  this->varsGenMap[simVar] = v25;
//
  simVar = "/controls/engines/current-engine/throttle";
  Var *v26 = new Var("/controls/engines/current-engine/throttle", /*"current-engine_throttle",*/ "", 0);
//  v26->genName = "current-engine_throttle";
//  v26->sim = "/controls/engines/current-engine/throttle";
//  v26->val = 0;
//  v26->direct = "";
  this->VarGenNames.emplace_back("current-engine_throttle");
  this->varsGenMap[simVar] = v26;
//
//  varName = "switches_master-avionics";
//  Var::Var *v27 = new Var::Var;
//  v27->genName = "switches_master-avionics";
//  v27->sim = "/controls/switches/master-avionics";
//  v27->val = 0;
//  v27->direct = "";
//  this->VarGenNames.emplace_back("switches_master-avionics");
//  this->varsGenMap[varName] = v27;
//
//  varName = "switches_starter";
//  Var::Var *v28 = new Var::Var;
//  v28->genName = "switches_starter";
//  v28->sim = "switches_starter";
//  v28->val = 0;
//  v28->direct = "";
//  this->VarGenNames.emplace_back("switches_starter");
//  this->varsGenMap[varName] = v28;
//
//  varName = "active-engine_auto-start";
//  Var::Var *v29 = new Var::Var;
//  v29->genName = "active-engine_auto-start";
//  v29->sim = "/engines/active-engine/auto-start";
//  v29->val = 0;
//  v29->direct = "";
//  this->VarGenNames.emplace_back("active-engine_auto-start");
//  this->varsGenMap[varName] = v29;
//
//  varName = "flight_speedbrake";
//  Var::Var *v30 = new Var::Var;
//  v30->genName = "flight_speedbrake";
//  v30->sim = "/controls/flight/speedbrake";
//  v30->val = 0;
//  v30->direct = "";
//  this->VarGenNames.emplace_back("flight_speedbrake");
//  this->varsGenMap[varName] = v30;
//
//  varName = "c172p_brake-parking";
//  Var::Var *v31 = new Var::Var;
//  v31->genName = "c172p_brake-parking";
//  v31->sim = "/sim/model/c172p/brake-parking";
//  v31->val = 0;
//  v31->direct = "";
//  this->VarGenNames.emplace_back("c172p_brake-parking");
//  this->varsGenMap[varName] = v31;
//
//  varName = "engine_primer";
//  Var::Var *v32 = new Var::Var;
//  v32->genName = "engine_primer";
//  v32->sim = "/controls/engines/engine/primer";
//  v32->val = 0;
//  v32->direct = "";
//  this->VarGenNames.emplace_back("engine_primer");
//  this->varsGenMap[varName] = v32;
//
//  varName = "current-engine_mixture";
//  Var::Var *v33 = new Var::Var;
//  v33->genName = "current-engine_mixture";
//  v33->sim = "/controls/engines/current-engine/mixture";
//  v33->val = 0;
//  v33->direct = "";
//  this->VarGenNames.emplace_back("current-engine_mixture");
//  this->varsGenMap[varName] = v33;
//
//  std::cout << varsGenMap.find("flight_flaps")->second->val << std::endl;
//
//  v24->val = 8;
//  std::cout << varsGenMap.find("flight_flaps")->second->val << std::endl;

}

