#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, M, R;
  cin >> N >> M >> R;
  vector<int> Cities(R);
  for (int i = 0; i < R; i++) cin >> Cities[i], Cities[i]--;
  sort(Cities.begin(), Cities.end());

  const long long INF = 1LL << 30;
  vector Dist(N, vector<long long>(N, INF));
  for (int i = 0; i < N; i++) Dist[i][i] = 0;
  for (int i = 0; i < M; i++) {
    int A, B;
    long long C;
    cin >> A >> B >> C;
    A--, B--;
    Dist[A][B] = Dist[B][A] = C;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        Dist[j][k] = min(Dist[j][k], Dist[j][i] + Dist[i][k]);
      }
    }
  }

  long long ans = INF;
  do {
    long long tmp = 0;
    for (int i = 1; i < R; i++) {
      tmp += Dist[Cities[i - 1]][Cities[i]];
    }
    ans = min(ans, tmp);
  } while (next_permutation(Cities.begin(), Cities.end()));

  cout << ans << endl;
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
