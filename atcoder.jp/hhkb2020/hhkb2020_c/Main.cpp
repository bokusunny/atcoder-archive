#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int i = 0; i < N; i++) cin >> P[i];
  set<int> st;
  for (int i = 0; i <= 200000; i++) st.insert(i);

  for (auto &p : P) {
    if (st.count(p)) st.erase(p);
    cout << *st.begin() << endl;
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
