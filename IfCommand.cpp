//
// Created by eden on 21/12/2019.
//

#include "IfCommand.h"
#include "Variable.h"
#include <Command.h>
#include <vector>
#include <list>
#include <unordered_map>
#include <lexer.h>
#include <Interpreter.h>
#include <Expression.h>
#include <Var.h>
#include <iostream>
#include <CommandsMap.h>

using namespace std;


/* calling the father constructor.
the params is the number of steps to advance in the array after execute */
IfCommand::IfCommand(int params) : Command() {
    this->numOfParams = params;
}

//trim the vector from the start after every execution / var definition
int IfCommand::execute(int i, vector<string> lexerData) {
    int j, oper = 0, expFlag = 0, k = 0, operFlag = 0, moveIndex = 0;
    char ch;
    double arg1 = 0, arg2 = 0; // arg1 - left exp, arg2 - right exp
    string varsToSet, token, exp1, exp2, sign;
    unordered_map<string, Var *> varMap;
    auto *i1 = new Interpreter();
    Expression *e1 = nullptr;
    Expression *e2 = nullptr;
    varsToSet = varsToString(varMap);
    i1->setVariables(varsToSet);
    // advance from the token 'if' to the next token - the argument in the 'if' condition
    i++;
    moveIndex++;
    token = lexerData.at(i);
    /// Calculate the expressions and sign of 'if' condition
    for (k = 0; k < token.size(); k++) {
        if (!(idenOperator(token[k]))) {
            if (expFlag == 0) {
                exp1.append(1, token[k]);
                e1 = i1->interpret(exp1);
                arg1 = e1->calculate();
                continue;
            } else {
                exp2.append(1, token[k]);
                e2 = i1->interpret(exp2);
                arg2 = e2->calculate();
                continue;
            }
        }
        if (idenOperator(token[k + 1])) {
            sign.append(1, token[k]);
            sign.append(1, token[k + 1]);
            oper = idenOperator(sign);
            operFlag = 1;
        } else if (!operFlag) {
            ch = token[k];
            oper = idenOperator(ch);
        }
        expFlag = 1;
    }
    k = 0;
    /// END OF Calculate the expressions and sign of 'if' condition
    i++; //j++
    moveIndex++;
    token = lexerData[i];
    k = stoi(token);
    //get index i (of lexerData) to the first line inside the 'if' condition
    i++; //j++
    moveIndex++;
    switch (oper) {
        // <
        case 1:
            if (arg1 < arg2) {
                //k is number of arguments to execute
                for (j = 0; j < k; j++) {
                    token = lexerData[i];
                    if (CommandsMap::getInstanceCommandMap()->getCommandMap().find(token)
                        != CommandsMap::getInstanceCommandMap()->getCommandMap().end()) {
                        //have to check this line!!!!!!
                        moveIndex += CommandsMap::getInstanceCommandMap()->getCommandMap().at(token)->execute(i, lexerData);
                        i += moveIndex;
                    }
                }
            }
            break;
            // >
        case 2:
            if (arg1 > arg2) {
                //k is number of arguments to execute
                for (j = 0; j < k; j++) {
                    token = lexerData[i];
                    if (CommandsMap::getInstanceCommandMap()->getCommandMap().find(token)
                        != CommandsMap::getInstanceCommandMap()->getCommandMap().end()) {
                        //have to check this line!!!!!!
                        moveIndex += CommandsMap::getInstanceCommandMap()->getCommandMap().at(token)->execute(i, lexerData);
                        i += moveIndex;
                    }
                }
            }
            break;
            // ==
        case 3:
            if (arg1 == arg2) {
                //k is number of arguments to execute
                for (j = 0; j < k; j++) {
                    token = lexerData[i];
                    if (CommandsMap::getInstanceCommandMap()->getCommandMap().find(token)
                        != CommandsMap::getInstanceCommandMap()->getCommandMap().end()) {
                        //have to check this line!!!!!!
                        moveIndex += CommandsMap::getInstanceCommandMap()->getCommandMap().at(token)->execute(i, lexerData);
                        i += moveIndex;
                    }
                }
            }
            break;
            // <=
        case 4:
            if (arg1 <= arg2) {
                //k is number of arguments to execute
                for (j = 0; j < k; j++) {
                    token = lexerData[i];
                    if (CommandsMap::getInstanceCommandMap()->getCommandMap().find(token)
                        != CommandsMap::getInstanceCommandMap()->getCommandMap().end()) {
                        //have to check this line!!!!!!
                        moveIndex += CommandsMap::getInstanceCommandMap()->getCommandMap().at(token)->execute(i, lexerData);
                        i += moveIndex;
                    }
                }
            }
            break;
            // >=
        case 5:
            if (arg1 >= arg2) {
                //k is number of arguments to execute
                for (j = 0; j < k; j++) {
                    token = lexerData[i];
                    if (CommandsMap::getInstanceCommandMap()->getCommandMap().find(token)
                        != CommandsMap::getInstanceCommandMap()->getCommandMap().end()) {
                        //have to check this line!!!!!!
                        moveIndex += CommandsMap::getInstanceCommandMap()->getCommandMap().at(token)->execute(i, lexerData);
                        i += moveIndex;
                    }
                }
            }
            break;
            // !=
        case 6:
            if (arg1 != arg2) {
                //k is number of arguments to execute
                for (j = 0; j < k; j++) {
                    token = lexerData[i];
                    if (CommandsMap::getInstanceCommandMap()->getCommandMap().find(token)
                        != CommandsMap::getInstanceCommandMap()->getCommandMap().end()) {
                        //have to check this line!!!!!!
                        moveIndex += CommandsMap::getInstanceCommandMap()->getCommandMap().at(token)->execute(i, lexerData);
                        i += moveIndex;
                    }
                }
            }
            break;
        default:
            break;
    }
    //instead of NumOfParams
    return moveIndex;
}

int IfCommand::idenOperator(char c) {
    int result;
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

int IfCommand::idenOperator(string s) {
    int result;
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

string IfCommand::varsToString(unordered_map<string, Var *> varMap) {
    string s;
    for (auto &it: varMap) {
        s.append(it.first);
        s.append("=");
        s.append(to_string(it.second->getVal()));
        s.append(";");
    }
    s.pop_back();
    cout << s;
    return s;
}


/*
   for (j = i; j < lexerData.size(); j++) {
       arg = lexerData.at(j);
       //didn't find the element
       if (varMap.find(arg) == varMap.end()) {
           if (numFlag == 0 && lexer::isNumber(arg)) {
               num1 = stof(arg);
               numFlag = 1;
           } else if (numFlag == 1 && lexer::isNumber(arg)) {
               num2 = stof(arg);
           } else if ((arg.length() == 1)) {
               ch = arg[0];
               oper = idenOperator(ch);
           } else if (arg.length() == 2) {
               oper = idenOperator(arg);
           } else {
               //throw "Couldn't find Variable (ifCommand)";
               continue;
           }
       } else if (varFlag == 0 && !lexer::isNumber(arg)) {
           var1 = varMap[arg];
           varFlag = 1;
       } else if (varFlag == 1 && !lexer::isNumber((arg))) {
           var2 = varMap[arg];
       }
   }
   switch (oper) {
       case 1:
           break;
       case 2:
           break;
       case 3:
           break;
       case 4:
           break;
       case 5:
           break;
       default:
           break;
   }
   */