#include "parser.h"
#include <bits/stdc++.h>

using namespace std;

// ---------------------- MAIN ----------------------
int main() {
  string code = R"(
shuru
  purno x = 9;
  vogno a = 3.976;
  purno a = 3;
  dekhao << a;
)";

  auto tokens = tokenize(code);
  Parser parser(tokens);
  parser.run();

  return 0;
}