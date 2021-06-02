#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  long long r, s, p;
  cin >> r >> s >> p;
  string t;
  cin >> t;

  int r_cnt = 0, s_cnt = 0, p_cnt = 0;

  for (int i = 0; i < (int)t.size(); i++) {
    char c = t.at(i);
    if (i - k >= 0 && t.at(i - k) == c) {
      t.at(i) = 'x';
      continue;
    }
    if (c == 'r') {
      p_cnt++;
    } else if (c == 's') {
      r_cnt++;
    } else {
      s_cnt++;
    }
  }

  cout << p_cnt * p + r_cnt * r + s_cnt * s << endl;

  return 0;
}
