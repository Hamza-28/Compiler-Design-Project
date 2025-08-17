#include "tokenizer.h"
#include <bits/stdc++.h>

using namespace std;

unordered_set<string> keywords = {"shuru",     "shesh",  "purno",
                                  "vogno",     "jodi",   "nohole",
                                  "jotokkhon", "dekhao", "nao", "shobdo"};

bool isNumber(const string &s) {
  bool dot = false;
  if (s.empty()) return false;
  for (int i = 0; i < (int)s.size(); i++) {
    if (isdigit(s[i])) continue;
    if (s[i] == '.' && !dot) {
      dot = true;
      continue;
    }
    return false;
  }
  return true;
}

// Validate identifier name
bool isValidIdentifier(const string &s) {
  if (s.empty()) return false;
  // Cannot start with a digit
  if (!(isalpha(s[0]) || s[0] == '_')) return false;
  // Remaining chars must be alnum or underscore
  for (int i = 1; i < s.size(); ++i) {
      if (!(isalnum(s[i]) || s[i] == '_')) return false;
  }
  // Not a C++ keyword
  if (keywords.count(s)) return false;
  
  return true;
}

// Remove comments from code
string removeComments(const string &code) {
  string result;
  bool inString = false;

  for (size_t i = 0; i < code.size(); i++) {
    char c = code[i];

    // Handle string literals
    if (c == '"' && (i == 0 || code[i - 1] != '\\')) {
      inString = !inString;
      result += c;
      continue;
    }

    // If we're inside a string, just add the character
    if (inString) {
      result += c;
      continue;
    }

    // Check for comment start
    if (c == '/' && i + 1 < code.size() && code[i + 1] == '/') {
      // Skip until end of line
      while (i < code.size() && code[i] != '\n') {
        i++;
      }
      // Add the newline if we found one
      if (i < code.size()) {
        result += '\n';
      }
    } else {
      result += c;
    }
  }

  return result;
}

vector<Token> tokenize(const string &code) {
  // First remove comments
  string cleanCode = removeComments(code);

  vector<Token> tokens;
  string buffer;
  bool inString = false;

  for (size_t i = 0; i < cleanCode.size(); i++) {
    char c = cleanCode[i];

    if (c == '"') {
      if (inString) {
        tokens.push_back({"STRING", buffer});
        buffer.clear();
        inString = false;
      } else {
        inString = true;
      }
      continue;
    }

    if (inString) {
      buffer += c;
      continue;
    }

    if (isspace(c)) {
      if (!buffer.empty()) {
        if (keywords.count(buffer)) {
          tokens.push_back({"KEYWORD", buffer});
        }
        else if (isNumber(buffer)) {
          if (buffer.find('.') != string::npos) {
            tokens.push_back({"VOGNO_LITERAL", buffer});
          } else {
            tokens.push_back({"PURNO_LITERAL", buffer});
          }
        }
        else {
          if (!isValidIdentifier(buffer)) {
            cerr << "Invalid identifier: " << buffer << endl;
          }
          else {
            tokens.push_back({"IDENTIFIER", buffer});
          }
        }
        buffer.clear();
      }
      continue;
    }

    if (c == '=' || c == '<' || c == '>' || c == '+' || c == '-' || c == '*' ||
        c == '/' || c == '{' || c == '}' || c == '(' || c == ')' || c == ';' || c == ',') {
      if (!buffer.empty()) {
        if (keywords.count(buffer))
          tokens.push_back({"KEYWORD", buffer});
        else if (isNumber(buffer)) {
          if (buffer.find('.') != string::npos) {
            tokens.push_back({"VOGNO_LITERAL", buffer});
          } else {
            tokens.push_back({"PURNO_LITERAL", buffer});
          }
        }
        else {
          if (!isValidIdentifier(buffer)) {
            cerr << "Invalid identifier: " << buffer << endl;
          }
          else {
            tokens.push_back({"IDENTIFIER", buffer});
          }
        }
        buffer.clear();
      }

      string op(1, c);
      // Handle -- (decrement)
      if (c == '-' && i + 1 < cleanCode.size() && cleanCode[i + 1] == '-') {
        op += '-';
        i++;
      }
      // Handle ++ (increment)
      else if (c == '+' && i + 1 < cleanCode.size() &&
               cleanCode[i + 1] == '+') {
        op += '+';
        i++;
      }
      // Handle << (left shift / output)
      else if (c == '<' && i + 1 < cleanCode.size() &&
               cleanCode[i + 1] == '<') {
        op += '<';
        i++;
      }
      // Handle >> (right shift / input)
      else if (c == '>' && i + 1 < cleanCode.size() &&
               cleanCode[i + 1] == '>') {
        op += '>';
        i++;
      }
      // Handle <=, >=, ==, !=
      else if ((c == '<' || c == '>' || c == '=' || c == '!') && i + 1 < cleanCode.size() &&
               cleanCode[i + 1] == '=') {
        op += '=';
        i++;
      }
      // Handle +=, -=, *=, /=
      else if ((c == '+' || c == '-' || c == '*' || c == '/') && i + 1 < cleanCode.size() && cleanCode[i+1] == '=') {
        op += '=';
        i++;
      }

      tokens.push_back({"OPERATOR", op});
      continue;
    }

    buffer += c;
  }

  if (!buffer.empty()) {
    if (keywords.count(buffer))
      tokens.push_back({"KEYWORD", buffer});
    else if (isNumber(buffer)) {
      if (buffer.find('.') != string::npos) {
        tokens.push_back({"VOGNO_LITERAL", buffer});
      } else {
        tokens.push_back({"PURNO_LITERAL", buffer});
      }
    }
    else {
      if (!isValidIdentifier(buffer)) {
        cerr << "Invalid identifier: " << buffer << endl;
      }
      else {
        tokens.push_back({"IDENTIFIER", buffer});
      }
    }
  }

  return tokens;
}
