#include <bits/stdc++.h>
using namespace std;

long long N, P, K;
long long A[41][41];
const long long INF = 1LL << 62;

int get_cnt(long long X) {
  vector<vector<long long>> dist(N, vector<long long>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dist[i][j] = A[i][j] != -1 ? A[i][j] : X;
    }
  }
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (dist[i][j] <= P) cnt++;
    }
  }

  return cnt;
}

long long get_border(long long k) {
  long long ok = 0, ng = INF;
  while (abs(ok - ng) > 1) {
    long long mid = (ok + ng) / 2;
    if (get_cnt(mid) >= k) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

int main() {
  cin >> N >> P >> K;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }

  long long L = get_border(K + 1);
  long long R = get_border(K);

  if (R - L >= 1000000000000LL)
    cout << "Infinity" << endl;
  else
    cout << R - L << endl;

  return 0;
}
