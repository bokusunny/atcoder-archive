#include <bits/stdc++.h>
using namespace std;

void solve() {
  int L, Q;
  cin >> L >> Q;
  set<int> st = {0, L};
  while (Q--) {
    int c, x;
    cin >> c >> x;
    if (c == 1) {
      st.insert(x);
    } else {
      auto itr = st.lower_bound(x);
      cout << *itr - *prev(itr) << endl;
    }
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
