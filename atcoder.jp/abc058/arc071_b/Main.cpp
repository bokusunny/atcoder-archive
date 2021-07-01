#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  long long N, M;
  cin >> N >> M;
  vector<long long> X(N), Y(M);
  for (int i = 0; i < N; i++) cin >> X[i];
  for (int i = 0; i < M; i++) cin >> Y[i];

  mint sum_x = 0, sum_y = 0;
  for (int i = 1; i < N; i++) {
    mint x = X[i] - X[i - 1];
    sum_x += x * i * (N - i);
  }
  for (int i = 1; i < M; i++) {
    mint y = Y[i] - Y[i - 1];
    sum_y += y * i * (M - i);
  }
  cout << (sum_x * sum_y).val() << endl;

  return 0;
}
