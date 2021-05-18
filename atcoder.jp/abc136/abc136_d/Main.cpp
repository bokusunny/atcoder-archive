#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  vector<int> table(s.size(), 0);
  int r_sequence = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'L') continue;

    r_sequence++;
    if (s[i + 1] == 'L') {
      table[i] += (r_sequence + 1) / 2;
      table[i + 1] += r_sequence / 2;
      r_sequence = 0;
    }
  }

  int l_sequence = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == 'R') continue;

    l_sequence++;
    if (s[i - 1] == 'R') {
      table[i] += (l_sequence + 1) / 2;
      table[i - 1] += l_sequence / 2;
      l_sequence = 0;
    }
  }

  for (int i = 0; i < s.size(); i++) cout << table[i] << " ";
  cout << endl;
}
