#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;

  for (int i = 0; i < (int)s.size(); i++) {
    if (s.at(i) == 'a') continue;

    int to_a = 'z' - s.at(i) + 1;
    if (to_a > k) continue;

    s.at(i) = 'a';
    k -= to_a;
  }

  if (k != 0) {
    k %= 26;
    s.at((int)s.size() - 1) += k;
  }

  cout << s << endl;

  return 0;
}
