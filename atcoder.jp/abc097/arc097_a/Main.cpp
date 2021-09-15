#include <bits/stdc++.h>
using namespace std;

void solve() {
  string S;
  int K;
  cin >> S >> K;
  int N = (int)S.size();

  set<string> st;
  for (int len = 1; len <= 5; len++) {
    for (int l = 0; l < N; l++) {
      st.insert(S.substr(l, len));
    }
  }

  vector<string> vec(st.begin(), st.end());
  cout << vec[K - 1] << endl;
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
