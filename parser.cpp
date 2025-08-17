#include "parser.h"
#include "tokenizer.h"
#include <bits/stdc++.h>
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

bool Parser::isDeclared(const std::string& varName) {
    return purnoTable.count(varName) || vognoTable.count(varName) || shobdoTable.count(varName);
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
      if (t.type == "PURNO_LITERAL" || t.type == "VOGNO_LITERAL" || t.type == "IDENTIFIER" ||
          (t.type == "OPERATOR" &&
           (t.value == "+" || t.value == "-" || t.value == "*" ||
            t.value == "/" || t.value == "<" || t.value == ">" ||
            t.value == "<=" || t.value == ">=" || t.value == "==" ||
            t.value == "!=")) ||
          t.value == "(" || t.value == ")") {
        get();  // consume the token

        if (t.type == "PURNO_LITERAL" || t.type == "VOGNO_LITERAL")
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
        if (purnoTable.count(var)) {
          st.push(purnoTable[var]);
        } else if (vognoTable.count(var)) {
          st.push(vognoTable[var]);
        } else {
          cerr << "Error: Undeclared variable '" << var << "' used in expression." << endl;
          return 0;
        }
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

string Parser::parseStringExpression() {
    string result = "";
    bool first = true;
    while (peek().type != "EOF" && peek().value != ";") {
        Token t = get();
        if (t.type == "STRING") {
            if (!first) {
                // This is not the first string, so we are concatenating
            }
            result += t.value;
        } else if (t.type == "OPERATOR" && t.value == "+") {
            // continue to next string
        } else if (t.type == "IDENTIFIER" && shobdoTable.count(t.value)) {
            result += shobdoTable[t.value];
        }
        else {
            // Invalid token in string expression
            cerr << "Error: Invalid token in string expression" << endl;
            break;
        }
        first = false;
    }
    return result;
}

void Parser::parseBlock() {
    while (peek().value != "}" && peek().type != "EOF") {
      parseStatement();
    }
    if (peek().value == "}") get();  // consume '}'
}

void Parser::parseStatement() {
    Token t = peek(); // Use peek to check the token without consuming
    if (t.type == "OPERATOR") {
        get(); // Consume the invalid token
        cerr << "Error: Invalid statement. Statements cannot start with an operator." << endl;
        // Skip to the end of the line to attempt recovery
        while(peek().value != ";" && peek().type != "EOF") get();
        if(peek().value == ";") get();
        return;
    }

    t = get(); // Consume the token now that we know it's not an operator
    if (t.value == "purno" || t.value == "vogno" || t.value == "shobdo") {
      string type = t.value;
      do {
        string var = get().value;
        if (isDeclared(var)) {
          cerr << "Error: Redeclaration of variable '" << var << "'." << endl;
        } else {
          if (type == "purno") purnoTable[var] = 0;
          else if (type == "vogno") vognoTable[var] = 0.0;
          else if (type == "shobdo") shobdoTable[var] = "";
        }
        if (peek().value == "=") {
            get(); // consume '='
            if (type == "purno") {
                double result = parseExpression();
                if (result != floor(result)) {
                    cerr << "Error: Type mismatch. Cannot assign a non-integer value to an integer variable '" << var << "'." << endl;
                } else {
                    purnoTable[var] = static_cast<int>(result);
                }
            } else if (type == "vogno") {
                vognoTable[var] = parseExpression();
            } else if (type == "shobdo") {
                shobdoTable[var] = parseStringExpression();
            }
        }
      } while (get().value == ",");
      // Semicolon is consumed by the loop
    } else if (t.value == "nao") {
        if (peek().value != ">>") {
            cerr << "Error: Expected '>>' after 'nao'." << endl;
            while(peek().value != ";" && peek().type != "EOF") get();
            if(peek().value == ";") get();
            return;
        }
        do {
            get(); // consume '>>'
            string var = get().value;
            cout << "Enter value for " << var << ": ";
            if (purnoTable.count(var)) {
                cin >> purnoTable[var];
            } else if (vognoTable.count(var)) {
                cin >> vognoTable[var];
            } else if (shobdoTable.count(var)) {
                cin >> shobdoTable[var];
            } else {
                cerr << "Error: Input to undeclared variable '" << var << "'." << endl;
            }
        } while (peek().value == ">>");
        if (peek().value == ";") get();  // consume ';'
    } 
    else if (t.value == "dekhao") {
        if (peek().value != "<<") {
            cerr << "Error: Expected '<<' after 'dekhao'." << endl;
            while(peek().value != ";" && peek().type != "EOF") get();
            if(peek().value == ";") get();
            return;
        }
        
        do {
            get(); // consume '<<'
            
            Token nxt = peek();
            if (nxt.type == "STRING" || nxt.type == "IDENTIFIER" || nxt.type == "PURNO_LITERAL" || nxt.type == "VOGNO_LITERAL") {
                get(); // consume value
                // --- Printing logic ---
                if (nxt.type == "STRING") {
                    string output = nxt.value;
                    for (size_t i = 0; i < output.length(); i++) {
                        if (output[i] == '\\' && i + 1 < output.length()) {
                            if (output[i + 1] == 'n') { cout << '\n'; i++; }
                            else if (output[i + 1] == 't') { cout << '\t'; i++; }
                            else { cout << output[i]; }
                        } else { cout << output[i]; }
                    }
                } else if (nxt.type == "IDENTIFIER") {
                    if (purnoTable.count(nxt.value)) { cout << purnoTable[nxt.value]; }
                    else if (vognoTable.count(nxt.value)) { cout << vognoTable[nxt.value]; }
                    else if (shobdoTable.count(nxt.value)) { cout << shobdoTable[nxt.value]; }
                    else { cerr << "Error: Undeclared variable '" << nxt.value << "'." << endl; }
                } else { // PURNO_LITERAL or VOGNO_LITERAL
                    cout << nxt.value;
                }
            } else {
                cerr << "Error: Expected a variable, string, or number after '<<', but got '" << nxt.value << "'." << endl;
                while(peek().value != ";" && peek().type != "EOF") get();
                if(peek().value == ";") get();
                return;
            }
        } while (peek().value == "<<");

        if (peek().value == ";") {
            get();  // consume ';'
        } else {
            cerr << "Error: Expected ';' at the end of the dekhao statement, but got '" << peek().value << "'." << endl;
            while(peek().value != ";" && peek().type != "EOF") get();
            if(peek().value == ";") get();
        }
    } else if (t.type == "IDENTIFIER") {
      // Handle assignments and increment/decrement
      string var = t.value;
      if (!isDeclared(var)) {
        cerr << "Error: Assignment to undeclared variable '" << var << "'." << endl;
        // Skip the rest of the statement to avoid further errors
        while (peek().type != "EOF" && peek().value != ";") {
          get();
        }
        if (peek().value == ";") get();
        return;
      }
      Token op = get();
      if (op.value == "=") {
        if (purnoTable.count(var)) {
            double result = parseExpression();
            if (result != floor(result)) {
                cerr << "Error: Type mismatch. Cannot assign a non-integer value to an integer variable '" << var << "'." << endl;
            } else {
                purnoTable[var] = static_cast<int>(result);
            }
        } else if (vognoTable.count(var)) {
            vognoTable[var] = parseExpression();
        } else if (shobdoTable.count(var)) {
            shobdoTable[var] = parseStringExpression();
        }
        if (peek().value == ";") get();
      } else if (op.value == "++") {
        if(purnoTable.count(var)) purnoTable[var]++;
        else if(vognoTable.count(var)) vognoTable[var]++;
        else cerr << "Error: Cannot increment non-numeric variable '" << var << "'." << endl;
        if (peek().value == ";") get();
      } else if (op.value == "--") {
        if(purnoTable.count(var)) purnoTable[var]--;
        else if(vognoTable.count(var)) vognoTable[var]--;
        else cerr << "Error: Cannot decrement non-numeric variable '" << var << "'." << endl;
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
        bodyParser.purnoTable = purnoTable;
        bodyParser.vognoTable = vognoTable;
        bodyParser.shobdoTable = shobdoTable;
        bodyParser.run();
        purnoTable = bodyParser.purnoTable;
        vognoTable = bodyParser.vognoTable;
        shobdoTable = bodyParser.shobdoTable;

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
    if (get().value != "shuru") {
        cerr << "Error: Expected 'shuru' at the beginning of the program." << endl;
        return;
    }

    while (peek().value != "shesh" && peek().type != "EOF") {
      parseStatement();
    }

    if (get().value != "shesh") {
        cerr << "Error: Expected 'shesh' at the end of the program." << endl;
    }
}
