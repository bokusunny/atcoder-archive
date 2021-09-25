#include <bits/stdc++.h>
using namespace std;

string convert_base_from_10(long long x, int to_base) {
  if (x == 0LL) return "0";

  string res = "";
  while (x > 0) {
    res = to_string(x % to_base) + res;
    x /= to_base;
  }

  return res;
}

void solve() {
  int N, L;
  cin >> N >> L;
  vector<string> ans;
  int base = 2;
  for (int i = 0; i < L - 1; i++) base *= 3;
  for (int i = 0; i < N; i++) {
    auto s = convert_base_from_10(base + i, 3);
    ans.push_back(s);
    for (int i = 0; i < 2; i++) {
      for (auto &c : s) {
        c = '0' + (c - '0' + 1) % 3;
      }
      ans.push_back(s);
    }
  }

  for (auto &s : ans) cout << s << endl;
}

void setcin() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  setcin();
  solve();

  return 0;
}
