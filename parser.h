#ifndef PARSER_H
#define PARSER_H

#include "tokenizer.h"
#include <bits/stdc++.h>
using namespace std;

class Parser {
  vector<Token> tokens;
  int pos = 0;
  unordered_map<string, double> symbolTable;
  
  Token peek();
  Token get();
  double parseExpression();
  void parseBlock();
  void parseStatement();
  void skipBlock();
  
public:
  Parser(vector<Token> tks);
  void run();
};

#endif // PARSER_H
