#ifndef PARSER_H
#define PARSER_H

#include "tokenizer.h"
#include <bits/stdc++.h>
using namespace std;

class Parser {
  unordered_map<string, int> purnoTable;
  unordered_map<string, double> vognoTable;
  unordered_map<string, string> shobdoTable;
  vector<Token> tokens;
  int pos = 0;

  Token peek();
  Token get();
  double parseExpression();
  void parseBlock();
  void parseStatement();
  void skipBlock();
  bool isDeclared(const string& varName);

 public:
  Parser(vector<Token> tks);
  void run();
};

#endif // PARSER_H
