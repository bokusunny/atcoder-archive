#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int ans = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s.at(i) == 'o') ans++;
  }

  if (ans + 15 - (int)s.size() >= 8) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
