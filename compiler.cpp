#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<string, ll> intVar;
map<string, double> doubleVar;
map<string, string> strVAr;

int main() {
  string code, token;
  
  while (cin >> token) {
    if (token == "shesh") break;
    if (token == "shuru") continue;
    code += token + " ";
  }

  cout << code << "\n";

  return 0;
}
