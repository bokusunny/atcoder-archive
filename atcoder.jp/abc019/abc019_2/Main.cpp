#include <bits/stdc++.h>
using namespace std;

template <class T>
vector<pair<T, int>> run_length_compress(vector<T> &vec) {
  int n = (int)vec.size();
  vector<pair<T, int>> res;
  for (int l = 0; l < n;) {
    int r = l + 1;
    while (r < n && vec[l] == vec[r]) r++;
    res.emplace_back(vec[l], r - l);
    l = r;
  }
  return res;
}
vector<pair<char, int>> run_length_compress(string &s) {
  int n = (int)s.size();
  vector<pair<char, int>> res;
  for (int l = 0; l < n;) {
    int r = l + 1;
    while (r < n && s[l] == s[r]) r++;
    res.emplace_back(s[l], r - l);
    l = r;
  }
  return res;
}

void solve() {
  string S;
  cin >> S;

  string ans;
  auto rl = run_length_compress(S);
  for (auto [c, cnt] : rl) {
    ans += c + to_string(cnt);
  }

  cout << ans << endl;
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
