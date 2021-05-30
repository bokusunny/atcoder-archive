#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  char prev = s[0];
  for (int i = 1; i < (int)s.size(); i++) {
    if (s[i] == prev) {
      cout << "Bad" << endl;
      return 0;
    }
    prev = s[i];
  }

  cout << "Good" << endl;

  return 0;
}
