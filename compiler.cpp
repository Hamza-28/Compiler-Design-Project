#include "parser.h"
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main() {
  ifstream file("code.txt");
  if (!file.is_open()) {
    cerr << "Error: Could not open code.txt" << endl;
    return 1;
  }

  string code;
  string line;
  while (getline(file, line)) {
    code += line + '\n';
  }
  file.close();

  auto tokens = tokenize(code);
  Parser parser(tokens);
  parser.run();

  return 0;
}