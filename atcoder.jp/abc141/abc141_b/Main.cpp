#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  for (int i = 1; i <= (int)s.size(); i++) {
    char c = s.at(i - 1);
    if (i % 2 == 1) {
      if (c == 'R' || c == 'U' || c == 'D') continue;
    } else {
      if (c == 'L' || c == 'U' || c == 'D') continue;
    }

    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;

  return 0;
}
