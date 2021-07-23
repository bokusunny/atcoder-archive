#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i], A[i]--;

  int logK = 1;
  while ((1LL << logK) <= K) logK++;

  // doubling[k][i] := 町iから2^k進んだところにある町
  vector<vector<int>> doubling(logK, vector<int>(N));
  for (int i = 0; i < N; i++) doubling[0][i] = A[i];

  for (int k = 0; k < logK - 1; k++) {
    for (int i = 0; i < N; i++) {
      doubling[k + 1][i] = doubling[k][doubling[k][i]];
    }
  }

  int now = 0, k = 0;
  while (K > 0) {
    if (K & 1) now = doubling[k][now];
    K >>= 1, k++;
  }

  cout << now + 1 << endl;

  return 0;
}
