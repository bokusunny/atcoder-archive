#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  set<pair<string, string>> st;
  for (int i = 0; i < N; i++) {
    string s, t;
    cin >> s >> t;
    if (st.count({s, t})) {
      cout << "Yes" << endl;
      return;
    }
    st.insert({s, t});
  }

  cout << "No" << endl;
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
