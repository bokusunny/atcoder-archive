#include <bits/stdc++.h>
using namespace std;

int N, M;

void solve() {
  cin >> N >> M;
  vector<long long> X(N), Y(N), Z(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i] >> Z[i];
  }

  const long long INF = 1LL << 62;
  long long ans = -INF;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        vector<long long> Val(N);
        for (int l = 0; l < N; l++) {
          long long val = 0;
          val += i ? X[l] : -X[l];
          val += j ? Y[l] : -Y[l];
          val += k ? Z[l] : -Z[l];
          Val[l] = val;
        }
        sort(Val.begin(), Val.end(), greater<long long>());
        long long tmp = 0;
        for (int l = 0; l < M; l++) tmp += Val[l];
        ans = max(ans, tmp);
      }
    }
  }

  cout << ans << endl;
}

int main() {
  solve();

  return 0;
}
