#include <bits/stdc++.h>
using namespace std;

int main() {
  string w;
  cin >> w;
  map<char, int> m;
  for (auto c : w) m[c]++;

  for (auto [c, cnt] : m) {
    if (cnt % 2 == 1) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}
