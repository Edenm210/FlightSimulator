//
// Created by yakir on 12/19/19.
//https://www.geeksforgeeks.org/singleton-design-pattern/

#include "lexer.h"
#include "VariableMap.h"
#include <vector>
#include "Parser.h"
#include "threadsManager.h"

using namespace std;

int main(int argc, char *argv[]) {
  VariableMap::setBool(false);
  string fileName = argv[1];
  vector<string> dataToParse;
  auto lex = new lexer;
  dataToParse = lex->lex(fileName);
  Parser::ParseCommand(dataToParse);
  threadsManager::getThread()->serverThread.join();
  threadsManager::getThread()->clientThread.join();

}

/*
  //openServerCommand *server = new openServerCommand(5400);
  int i, j = 0;
  float updatedVal;
  string token  = "";
  //char buffer[2048] = {0};
  char buffer[2048] = {"0.132548,0.132562,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000"
                       ",0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000"
                       ",0.000000,0.000000,0.272555,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000"
                       ",0.000000,0.000000,0.000000,0.000000,0.000000,0.000001"};
  for (i = 0; i < 36; i++) {
      while (buffer[j] != '\n' && buffer[j] != ',') {
          token.append(1, buffer[j]);
          j++;
      }
      updatedVal = stof(token);
      token.clear();
      std::cout<< updatedVal<<endl;
      if (buffer[j] == ',') {
          j++;
      }
  }

  */
/*
int i = 0;
string out;
VariableMap *vm = VariableMap::getInstanceVarsMap();
vm->print();
out = IfCommand::varsToString(vm->getVarsMap());
*/

/*   lexer   */

/*
int i;
string file;
vector<string> args;
file = argv[1];
lexer *lex = new lexer;
args = lex->lex(file);
for (i = 0; i < args.size(); i++) {
    cout<<args[i]<<endl;
}
return 0;

*/