#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  vector<int> idx;
  bool plus = true;
  for (int i = 1; i < N; i++) {
    if (plus) {
      if (A[i - 1] > A[i]) {
        plus = false;
        idx.push_back(i - 1);
      }
    } else {
      if (A[i - 1] < A[i]) {
        plus = true;
        idx.push_back(i - 1);
      }
    }
  }
  if (!plus) idx.push_back(N - 1);

  if ((int)idx.size() & 1) idx.pop_back();
  vector<int> ans(N);
  for (auto i : idx) ans[i] = 1;

  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
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
