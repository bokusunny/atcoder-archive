#include <bits/stdc++.h>
using namespace std;

string S;
set<char> st;

void solve() {
  cin >> S;
  for (int i = 0; i < 4; i++) st.insert(S[i]);
  if (st.size() == 1) {
    cout << "Weak" << endl;
    return;
  }
  int prev = S[0] - '0';
  for (int i = 1; i < 4; i++) {
    int cur = S[i] - '0';
    if (cur == 0) {
      if (prev != 9) {
        cout << "Strong" << endl;
        return;
      }
    } else {
      if (cur != prev + 1) {
        cout << "Strong" << endl;
        return;
      }
    }
    prev = cur;
  }
  cout << "Weak" << endl;
}

void cinout() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

int main() {
  cinout();
  solve();

  return 0;
}
