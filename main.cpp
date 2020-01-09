
#include "Lexer.h"
#include "VariableMap.h"
#include <vector>
#include "Parser.h"

using namespace std;

int main(int argc, char *argv[]) {
    //instantiates the maps of the vars
    VariableMap::getInstanceVarsMap();
    //sets a boolean in order to control the other threads (server and client)
    VariableMap::setBool(false);
    //getting the file name
    string fileName = argv[1];
    vector<string> dataToParse;
    auto lex = new Lexer;
    //tokenizing the text with the Lexer
    dataToParse = lex->lex(fileName);
    // executing the relevant actions (commands) according to the vector provided by the Lexer
    Parser::ParseCommand(dataToParse);
    return 0;
}