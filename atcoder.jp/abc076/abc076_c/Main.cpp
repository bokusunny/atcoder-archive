#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  string ans = "UNRESTORABLE";

  for (int start = 0; start < (int)(s.size() - t.size() + 1); start++) {
    bool is_ok = true;
    string tmp = s;
    for (int i = 0; i < int(t.size()); i++) {
      if (s[start + i] != '?' && s[start + i] != t[i]) {
        is_ok = false;
        break;
      }
      tmp[start + i] = t[i];
    }
    if (is_ok) {
      for (int i = 0; i < (int)(s.size()); i++) {
        if (tmp[i] == '?') tmp[i] = 'a';
      }
      if (ans == "UNRESTORABLE" || ans > tmp) ans = tmp;
    }
  }

  cout << ans << endl;

  return 0;
}
