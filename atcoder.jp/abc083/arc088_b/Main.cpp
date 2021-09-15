#include <bits/stdc++.h>
using namespace std;

void solve() {
  string S;
  cin >> S;
  int N = (int)S.size();

  int l = 0, r = N - 1;
  int a = 0, b = N;
  while (l < r) {
    if (S[l] != S[l + 1]) a = l + 1;
    if (S[r] != S[r - 1]) b = r;
    l++;
    r--;
  }

  cout << min(N - a, b) << endl;
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
