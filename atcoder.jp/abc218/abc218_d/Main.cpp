#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;

  set<pair<int, int>> st;
  vector<pair<int, int>> P(N);
  for (int i = 0; i < N; i++) {
    cin >> P[i].first >> P[i].second;
    st.insert(P[i]);
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (P[i].first < P[j].first && P[i].second < P[j].second) {
        pair<int, int> p1 = {P[i].first, P[j].second};
        pair<int, int> p2 = {P[j].first, P[i].second};
        if (st.count(p1) && st.count(p2)) ans++;
      }
    }
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
