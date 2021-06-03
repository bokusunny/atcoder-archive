#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  const int s_size = (int)s.size();
  if (s_size == 1) {
    cout << s << endl;
    return 0;
  }

  long long ans = 0;
  for (int i = 0; i < (1 << (s_size - 1)); i++) {
    string tmp;
    tmp += s.at(0);
    long long total = 0;
    for (int j = 0; j < (s_size - 1); j++) {
      if ((i >> j) & 1) {
        total += stoi(tmp);
        tmp = "";
        tmp += s.at(j + 1);
      } else {
        tmp += s.at(j + 1);
      }
    }
    total += stoll(tmp);
    ans += total;
  }

  cout << ans << endl;

  return 0;
}
