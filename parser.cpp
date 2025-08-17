#include <bits/stdc++.h>
#include "tokenizer.h"
#include "parser.h"

using namespace std;

Parser::Parser(vector<Token> tks) : tokens(tks) {}

Token Parser::peek() {
    if (pos < (int)tokens.size()) return tokens[pos];
    return {"EOF", ""};
}

Token Parser::get() {
    if (pos < (int)tokens.size()) return tokens[pos++];
    return {"EOF", ""};
}

double Parser::parseExpression() {
    vector<string> output;
    stack<string> ops;

    auto precedence = [](const string &op) {
      if (op == "<" || op == ">" || op == "<=" || op == ">=" || op == "==" ||
          op == "!=")
        return 3;
      if (op == "+" || op == "-") return 1;
      if (op == "*" || op == "/") return 2;
      return 0;
    };

    // Handle comparison operators
    while (peek().type != "EOF") {
      Token t = peek();
      if (t.type == "NUMBER" || t.type == "IDENTIFIER" ||
          (t.type == "OPERATOR" &&
           (t.value == "+" || t.value == "-" || t.value == "*" ||
            t.value == "/" || t.value == "<" || t.value == ">" ||
            t.value == "<=" || t.value == ">=" || t.value == "==" ||
            t.value == "!=")) ||
          t.value == "(" || t.value == ")") {
        get();  // consume the token

        if (t.type == "NUMBER")
          output.push_back(t.value);
        else if (t.type == "IDENTIFIER")
          output.push_back("@" + t.value);
        else if (t.value == "(")
          ops.push(t.value);
        else if (t.value == ")") {
          while (!ops.empty() && ops.top() != "(") {
            output.push_back(ops.top());
            ops.pop();
          }
          if (!ops.empty()) ops.pop();  // remove the '('
        } else if (t.type == "OPERATOR") {
          while (!ops.empty() && ops.top() != "(" &&
                 precedence(ops.top()) >= precedence(t.value)) {
            output.push_back(ops.top());
            ops.pop();
          }
          ops.push(t.value);
        }
      } else {
        break;  // Stop if we encounter something that's not part of the
                // expression
      }
    }

    while (!ops.empty()) {
      output.push_back(ops.top());
      ops.pop();
    }

    // Evaluate postfix expression
    stack<double> st;
    for (const string &tok : output) {
      if (tok[0] == '@') {
        string var = tok.substr(1);
        st.push(symbolTable[var]);
      } else if (isNumber(tok)) {
        st.push(stod(tok));
      } else {
        if (st.size() < 2) {
          cerr << "Error: Invalid expression" << endl;
          return 0;
        }
        double b = st.top();
        st.pop();
        double a = st.top();
        st.pop();
        if (tok == "+")
          st.push(a + b);
        else if (tok == "-")
          st.push(a - b);
        else if (tok == "*")
          st.push(a * b);
        else if (tok == "/") {
          if (b == 0) {
            cerr << "Error: Division by zero" << endl;
            return 0;
          }
          st.push(a / b);
        } else if (tok == "<")
          st.push(a < b ? 1 : 0);
        else if (tok == ">")
          st.push(a > b ? 1 : 0);
        else if (tok == "<=")
          st.push(a <= b ? 1 : 0);
        else if (tok == ">=")
          st.push(a >= b ? 1 : 0);
        else if (tok == "==")
          st.push(a == b ? 1 : 0);
        else if (tok == "!=")
          st.push(a != b ? 1 : 0);
      }
    }
    return st.empty() ? 0 : st.top();
}

void Parser::parseBlock() {
    while (peek().value != "}" && peek().type != "EOF") {
      parseStatement();
    }
    if (peek().value == "}") get();  // consume '}'
}

void Parser::parseStatement() {
    Token t = get();
    if (t.value == "purno" || t.value == "vogno") {
      string var = get().value;
      get();  // '='
      double val = parseExpression();
      symbolTable[var] = val;
      if (peek().value == ";") get();  // consume ';'
    } else if (t.value == "nao") {
      get();  // '>>'
      string var = get().value;
      if (peek().value == ";") get();  // consume ';'
      cout << "Enter value for " << var << ": ";
      double input;
      cin >> input;
      symbolTable[var] = input;
    } else if (t.value == "dekhao") {
      while (peek().value != ";" && peek().type != "EOF") {
        Token nxt = get();
        if (nxt.type == "STRING") {
          string output = nxt.value;
          // Handle escape sequences
          for (size_t i = 0; i < output.length(); i++) {
            if (output[i] == '\\' && i + 1 < output.length()) {
              if (output[i + 1] == 'n') {
                cout << '\n';
                i++;  // skip the 'n'
              } else if (output[i + 1] == 't') {
                cout << '\t';
                i++;  // skip the 't'
              } else {
                cout << output[i];
              }
            } else {
              cout << output[i];
            }
          }
        } else if (nxt.type == "IDENTIFIER") {
          cout << symbolTable[nxt.value];
        } else if (nxt.type == "NUMBER") {
          cout << nxt.value;
        } else if (nxt.value == "<<") {
          continue;  // skip output operators
        }
      }
      if (peek().value == ";") get();  // consume ';'
      if (peek().value != "<<" || (pos > 0 && tokens[pos - 1].value != "<<")) {
        // Don't add newline if this is part of a chained output
        cout << endl;
      }
    } else if (t.type == "IDENTIFIER") {
      // Handle assignments and increment/decrement
      string var = t.value;
      Token op = get();
      if (op.value == "=") {
        double val = parseExpression();
        symbolTable[var] = val;
        if (peek().value == ";") get();
      } else if (op.value == "++") {
        symbolTable[var]++;
        if (peek().value == ";") get();
      } else if (op.value == "--") {
        symbolTable[var]--;
        if (peek().value == ";") get();
      }
    } else if (t.value == "jodi") {
      get();  // '('
      double cond = parseExpression();
      get();  // ')'
      get();  // '{'

      if (cond != 0) {
        parseBlock();
        // skip any following `nohole`
        while (peek().value == "nohole") {
          get();  // consume 'nohole'
          if (peek().value == "jodi") {
            // skip `nohole jodi (...) {...}`
            get();              // 'jodi'
            get();              // '('
            parseExpression();  // skip condition
            get();              // ')'
            get();              // '{'
            skipBlock();
          } else if (peek().value == "{") {
            get();  // '{'
            skipBlock();
          }
        }
      } else {
        skipBlock();
        // handle `nohole jodi` and `nohole`
        bool executed = false;
        while (peek().value == "nohole" && !executed) {
          get();  // consume 'nohole'
          if (peek().value == "jodi") {
            get();  // 'jodi'
            get();  // '('
            double elifCond = parseExpression();
            get();  // ')'
            get();  // '{'
            if (elifCond != 0) {
              parseBlock();
              executed = true;
            } else {
              skipBlock();
            }
          } else if (peek().value == "{") {
            get();  // '{'
            if (!executed) {
              parseBlock();
              executed = true;
            } else {
              skipBlock();
            }
          }
        }
      }
    } else if (t.value == "jotokkhon") {
      int loopStart = pos - 1;  // Save position before 'jotokkhon'

      get();  // '('
      double cond = parseExpression();
      get();  // ')'
      get();  // '{'

      // Save the loop body tokens
      vector<Token> loopBody;
      int braceCount = 1;
      while (braceCount > 0 && peek().type != "EOF") {
        Token bodyToken = get();
        if (bodyToken.value == "{")
          braceCount++;
        else if (bodyToken.value == "}") {
          braceCount--;
          if (braceCount == 0) break;
        }
        loopBody.push_back(bodyToken);
      }

      // Execute the loop
      while (cond != 0) {
        // Create a new parser for the loop body
        Parser bodyParser(loopBody);
        bodyParser.symbolTable = symbolTable;  // Share symbol table
        bodyParser.run();
        symbolTable = bodyParser.symbolTable;  // Update symbol table

        // Re-evaluate condition
        int savedPos = pos;
        pos = loopStart + 1;  // Position after 'jotokkhon'
        get();                // '()'
        cond = parseExpression();
        get();           // ')'
        pos = savedPos;  // Restore position
      }
    }
}

void Parser::skipBlock() {
    int depth = 1;
    while (depth > 0 && peek().type != "EOF") {
      Token x = get();
      if (x.value == "{")
        depth++;
      else if (x.value == "}")
        depth--;
    }
}

void Parser::run() {
    while (peek().type != "EOF") {
      parseStatement();
    }
}
