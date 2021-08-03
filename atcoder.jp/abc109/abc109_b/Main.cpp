#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> W;

void solve() {
  cin >> N;
  W.resize(N);
  map<string, int> mp;
  for (int i = 0; i < N; i++) {
    cin >> W[i];
    if (mp.count(W[i])) {
      cout << "No" << endl;
      return;
    }
    mp[W[i]]++;
  }

  char prev = W[0][0];
  for (auto s : W) {
    if (s[0] != prev) {
      cout << "No" << endl;
      return;
    }
    prev = s[(int)s.size() - 1];
  }
  cout << "Yes" << endl;
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
