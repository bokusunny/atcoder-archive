#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, K;
  cin >> N >> K;
  vector<long long> A(N);
  map<long long, long long> m;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    m[A[i]] = i;
  }

  auto base = K / N;
  vector<long long> ans(N, base);
  auto amari = K % N;
  for (auto [num, i] : m) {
    if (amari == 0) break;
    ans[i]++;
    amari--;
  }

  for (auto a : ans) cout << a << endl;

  return 0;
}
