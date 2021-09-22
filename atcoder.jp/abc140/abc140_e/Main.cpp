#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> A(N + 1), Pos(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    Pos[A[i]] = i;
  }
  A.push_back(0);
  multiset<int> st;
  st.insert(0);
  st.insert(0);
  st.insert(N + 1);
  st.insert(N + 1);

  long long ans = 0;
  for (int i = N; i >= 1; i--) {
    auto itr = st.lower_bound(Pos[i]);
    auto upper = *itr;
    auto upperupper = *next(itr);
    auto lower = *prev(itr);
    auto lowerlower = *prev(prev(itr));
    ans += 1LL * i * (upper - Pos[i]) * (lower - lowerlower);
    ans += 1LL * i * (upperupper - upper) * (Pos[i] - lower);
    st.insert(Pos[i]);
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
