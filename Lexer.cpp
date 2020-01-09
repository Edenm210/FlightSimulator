

#include "Lexer.h"
#include <vector>
#include <iostream>

using namespace std;

Lexer::Lexer() {
    tok = "";
}

Lexer::~Lexer() {
    tokens.clear();
}

//checks if a string is a number (more than one digit)
bool Lexer::isNumber(string s) {
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == 0)
            return false;

    return true;
}

/*
 * this function breaks each line in the script (".txt") to tokens and inserts it to a vector.
 * the vector will be used in the Parser class in order to know what command to execute, when,
 * and with which parameters
 * */
vector<string> Lexer::lex(string fileName) {
    char ch;
    streampos funcBegin;
    int i, j = 0, flag, skipSpace = 0, countFuncArgs = 0, foundWhile, foundIf;
    string line;
    ifstream simData(fileName, ios::in);
    if (!simData) {
        throw "Couldn't open File";
    }
    //reads lines until the script (".txt") ends
    while (!simData.eof()) {
        getline(simData, line);
        for (i = 0; i < line.length(); i++) {
            foundWhile = line.find("while");
            foundIf = line.find("if");
            if (foundWhile != -1 || foundIf != -1) {
                while (line[i] != ' ' && line[i] != '\t') {
                    tok += line[i];
                    i++;
                }
                tokens.push_back(tok);
                tok = "";
                i++;
                while (line[i] != '{') {
                    tok += line[i];
                    i++;
                }
                tokens.push_back(tok);
                tok = "";
                funcBegin = simData.tellg();  // stores the position
                while (ch != '}') {
                    getline(simData, line);
                    ch = line[0];
                    if (line.find('}') != std::string::npos) {
                        countFuncArgs += 1;
                        break;
                    }
                        countFuncArgs += 1;
                }
                simData.seekg(funcBegin);   // get back to the position
                tokens.push_back(to_string(countFuncArgs - 1));
                tok = "";
                skipSpace = 1;
                continue;
            }
            ch = line[i];
            if (isalpha(ch)) {
                tok += ch;
                skipSpace = 0;
                continue;
            } else if (isdigit(ch)) {
                tok += ch;
                skipSpace = 0;
                continue;
            } else {
                switch (ch) {
                    case '(':
                        tokens.push_back(tok);
                        tok = "";
                        if (line[i + 1] != '"') {
                            while (line[i + 1] != ')') {
                                tok += line[i + 1];
                                i++;
                            }
                            continue;
                        }
                        if (line.find_first_of(',')) {
                            flag = 1;
                        }
                        skipSpace = 0;
                        continue;
                    case ')':
                        tokens.push_back(tok);
                        tok = "";
                        skipSpace = 1;
                        continue;
                    case '"':
                        if (line[i - 1] == '(') {
                            while (line[i + 1] != '"') {
                                tok += line[i + 1];
                                i++;
                            }
                            i++;
                            continue;
                        }
                        continue;
                    case '.':
                        tok += ch;
                        skipSpace = 0;
                        continue;
                    case ',':
                        tokens.push_back(tok);
                        tok = "";
                        skipSpace = 1;
                        continue;
                    case '/':
                        tok += ch;
                        skipSpace = 0;
                        continue;
                    case '>':
                        if (line[i - 1] == '-' || line[i + 1] == '=') {
                            tok += ch;
                            tokens.push_back(tok);
                            tok = "";
                            skipSpace = 1;

                        }
                        continue;
                    case '<':
                        if (line[i + 1] == '-' || line[i + 1] == '=') {
                            tok += ch;
                            skipSpace = 0;
                        } else {
                            tok += ch;
                            tokens.push_back(tok);
                            tok = "";
                            skipSpace = 1;
                        }
                        continue;
                    case '-':
                        if (line[i - 1] == '<') {
                            tok += ch;
                            skipSpace = 0;
                            continue;
                        } else if (line[i + 1] == '>') {
                            tok += ch;
                            skipSpace = 0;
                            continue;
                        } else {
                            while (line[i] != ')' && line[i] != '"') {
                                tok += line[i];
                                i++;
                            }
                        }
                        continue;
                    case '=':
                        if (line[i - 1] != '<' && line[i - 1] != '>') {
                            i++;
                            tokens.emplace_back("=");
                            while (i < line.length()) {
                                if (line[i] != ' ' && line[i] != '\t') {
                                    tok += line[i];
                                }
                                i++;
                            }
                        }
                        if (!isNumber(tokens.back())) {
                            if (line[i - 1] == '<' || line[i - 1] == '>') {
                                tok += ch;
                            }
                            tokens.push_back(tok);
                            tok = "";
                            skipSpace = 1;
                        }
                        tok = "";
                        continue;
                    case '{':
                        funcBegin = simData.tellg();  // stores the position
                        while (ch != '}') {
                            getline(simData, line);
                            ch = line[0];
                            countFuncArgs += 1;
                        }
                        simData.seekg(funcBegin);   // get back to the position
                        tokens.push_back(to_string(countFuncArgs - 1));
                        tok = "";
                        skipSpace = 1;
                        continue;
                    case '}':
                        continue;
                    case ' ':
                        if (skipSpace != 1 && tok != "" && tok != " ") {
                            tokens.push_back(tok);
                            tok = "";
                        }
                        continue;
                    case '\t':
                        if (skipSpace != 1 && tok != "" && tok != " ")
                        tokens.push_back(tok);
                        tok = "";
                        continue;
                }
            }
        }
        flag = 0;
        skipSpace = 0;
        countFuncArgs = 0;
    }
    //close the file
    simData.close();
    //Special token the will mark the end of the data in the vector
    tokens.emplace_back("EndOfProgram - Airplane is airborne");
    return tokens;
}

