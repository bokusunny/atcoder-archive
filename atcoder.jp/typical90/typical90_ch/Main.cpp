#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> X(Q), Y(Q), Z(Q);
  vector<long long> W(Q);
  for (int i = 0; i < Q; i++) {
    cin >> X[i] >> Y[i] >> Z[i] >> W[i];
    X[i]--, Y[i]--, Z[i]--;
  }

  mint ans = 1;
  // i番目のbitを見る
  for (int i = 0; i < 60; i++) {
    // 各Wについて、i番目のbitが立っているか
    vector<bool> F(Q);
    for (int j = 0; j < Q; j++) {
      F[j] = (W[j] >> i & 1);
    }

    mint tmp = 0;

    for (int bit = 0; bit < 1 << N; bit++) {
      bool is_ok = true;
      // bit >> j & 1 == 1は、A_jのi番目のbitが立っていることを示す
      for (int q = 0; q < Q; q++) {
        auto x_flag = bit >> X[q] & 1;
        auto y_flag = bit >> Y[q] & 1;
        auto z_flag = bit >> Z[q] & 1;
        if ((x_flag | y_flag | z_flag) != F[q]) {
          is_ok = false;
          break;
        }
      }
      if (is_ok) tmp++;
    }
    ans *= tmp;
  }

  cout << ans.val() << endl;

  return 0;
}
