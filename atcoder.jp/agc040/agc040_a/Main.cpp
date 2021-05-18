#include <bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

template <typename T>
inline bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
// --------------------------------------------------------
int main() {
  string s;
  cin >> s;

  // vec[i]: aiの左に<が何個連続しているか
  const int vec_size = s.size() + 1;
  vector<int> vec(vec_size, 0);
  int current_sequence = 0;
  rep(i, s.size()) {
    char c = s[i];
    current_sequence = c == '<' ? current_sequence + 1 : 0;
    vec.at(i + 1) = current_sequence;
  }

  reverse(all(s));
  vector<int> vec2(vec_size, 0);
  current_sequence = 0;
  rep(i, s.size()) {
    char c = s[i];
    current_sequence = c == '>' ? current_sequence + 1 : 0;
    vec2.at(vec_size - 1 - (i + 1)) = current_sequence;
  }

  long long ans = 0;
  rep(i, vec_size) { ans += max(vec.at(i), vec2.at(i)); }
  cout << ans << endl;
}
