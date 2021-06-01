#include <bits/stdc++.h>
using namespace std;

bool solve(string s) {
  if ((int)s.size() == 1) return stoi(s) == 8;

  if ((int)s.size() == 2) {
    if (stoi(s) % 8 == 0) return true;
    swap(s[0], s[1]);
    return stoi(s) % 8 == 0;
  }

  vector<int> cnt(10, 0);
  for (auto c : s) cnt[c - '0']++;

  for (int i = 112; i < 1000; i += 8) {
    string is = to_string(i);

    bool is_ok = true;
    auto cnt_copy = cnt;
    for (char c : is) {
      cnt_copy.at(c - '0')--;
      if (cnt_copy.at(c - '0') < 0) {
        is_ok = false;
        break;
      }
    }
    if (is_ok) return true;
  }
  return false;
}

int main() {
  string s;
  cin >> s;

  string ans = solve(s) ? "Yes" : "No";
  cout << ans << endl;

  return 0;
}