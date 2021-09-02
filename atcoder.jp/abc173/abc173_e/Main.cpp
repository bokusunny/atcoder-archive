#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

void solve() {
  int N, K;
  cin >> N >> K;
  bool is_all_minus = true;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] >= 0) is_all_minus = false;
  }

  if (N == K) {
    mint ans = 1;
    for (auto &a : A) ans *= a;
    cout << ans.val() << endl;
  } else if (is_all_minus && (K & 1)) {
    sort(A.begin(), A.end(), greater<int>());
    mint ans = 1;
    for (int i = 0; i < K; i++) ans *= A[i];
    cout << ans.val() << endl;
  } else {
    vector<int> Minus, Plus;
    for (auto &a : A) {
      if (a >= 0)
        Plus.push_back(a);
      else
        Minus.push_back(a);
    }
    sort(Plus.begin(), Plus.end(), greater<int>());
    sort(Minus.begin(), Minus.end());

    if (K & 1) {
      vector<long long> Bucket;
      for (int i = 1; i < (int)Plus.size() - 1; i += 2) {
        Bucket.push_back(1LL * Plus[i] * Plus[i + 1]);
      }
      for (int i = 0; i < (int)Minus.size() - 1; i += 2) {
        Bucket.push_back(1LL * Minus[i] * Minus[i + 1]);
      }
      sort(Bucket.begin(), Bucket.end(), greater<long long>());
      mint ans = Plus[0];
      for (int i = 0; i < K / 2; i++) {
        ans *= Bucket[i];
      }
      cout << ans.val() << endl;
    } else {
      vector<long long> Bucket;
      for (int i = 0; i < (int)Plus.size() - 1; i += 2) {
        Bucket.push_back(1LL * Plus[i] * Plus[i + 1]);
      }
      for (int i = 0; i < (int)Minus.size() - 1; i += 2) {
        Bucket.push_back(1LL * Minus[i] * Minus[i + 1]);
      }
      sort(Bucket.begin(), Bucket.end(), greater<long long>());
      mint ans = 1;
      for (int i = 0; i < K / 2; i++) {
        ans *= Bucket[i];
      }
      cout << ans.val() << endl;
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
