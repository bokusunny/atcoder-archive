#include <bits/stdc++.h>
using namespace std;

void solve() {
  string S;
  cin >> S;
  int N = (int)S.size();

  if (S.substr(N - 2) == "er") {
    cout << "er" << endl;
  } else {
    cout << "ist" << endl;
  }
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
