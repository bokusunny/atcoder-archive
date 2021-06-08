#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  map<char, int> ms;
  map<char, int> mt;
  for (auto c : s) ms[c]++;
  for (auto c : t) mt[c]++;

  vector<int> vs;
  vector<int> vt;
  for (auto [key, cnt] : ms) vs.push_back(cnt);
  for (auto [key, cnt] : mt) vt.push_back(cnt);
  sort(vs.begin(), vs.end());
  sort(vt.begin(), vt.end());

  if (vs == vt) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
