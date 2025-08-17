#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <bits/stdc++.h>
using namespace std;

struct Token {
  string type;
  string value;
};

vector<Token> tokenize(const string &code);
bool isNumber(const string &s);
bool isValidIdentifier(const string &s);
string removeComments(const string &code);


#endif // TOKENIZER_H
