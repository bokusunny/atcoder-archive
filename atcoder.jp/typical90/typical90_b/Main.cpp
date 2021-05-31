#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  if (n % 2 == 1) return 0;

  auto check = [](string s) {
    int a = 0;
    int b = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == '(') {
        a++;
      } else {
        b++;
      }
      if (a < b) return false;
    }
    if (a != b) return false;
    return true;
  };

  for (int i = 0; i < (1 << n); i++) {
    string s = "";
    for (int j = 0; j < n; j++) {
      if (i >> j & 1) {
        s = ')' + s;
      } else {
        s = '(' + s;
      }
    }
    if (check(s)) cout << s << endl;
  }

  return 0;
}
