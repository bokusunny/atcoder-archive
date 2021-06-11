#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  getline(cin, s);

  char prev_c;
  for (int i = 0; i < (int)s.size(); i++) {
    auto c = s.at(i);
    if (i != 0 && prev_c == ' ' && c == ' ') continue;
    if (c == ' ') {
      cout << ',';
    } else {
      cout << c;
    }

    prev_c = c;
  }

  cout << endl;

  return 0;
}
