

#ifndef EX3_LEXER_H
#define EX3_LEXER_H

#include <cstring>
#include <vector>
#include <fstream>
#include <vector>

using namespace std;


class Lexer {
private:
    string tok;
    vector<string> tokens;
public:
    Lexer();

    ~Lexer();

    vector<string> lex(string fileName);

    static bool isNumber(string s);
};


#endif //EX3_LEXER_H
