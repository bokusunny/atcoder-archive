#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;

void solve() {
  cin >> N;
  A.resize(N);
  vector<long long> cnt(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
    cnt[A[i]]++;
  }
  long long all = 0;
  for (int i = 0; i < N; i++) {
    if (cnt[i] >= 2) {
      all += cnt[i] * (cnt[i] - 1) / 2;
    }
  }
  for (int i = 0; i < N; i++) {
    cout << all - cnt[A[i]] * (cnt[A[i]] - 1) / 2 + (cnt[A[i]] - 1) * (cnt[A[i]] - 2) / 2 << endl;
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
