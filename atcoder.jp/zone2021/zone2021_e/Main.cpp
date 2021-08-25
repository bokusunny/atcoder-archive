#include <bits/stdc++.h>
using namespace std;

void solve() {
  int R, C;
  cin >> R >> C;
  vector A(R, vector<int>(C - 1)), B(R - 1, vector<int>(C));
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < R - 1; i++) {
    for (int j = 0; j < C; j++) {
      cin >> B[i][j];
    }
  }

  const int INF = 1 << 30;
  vector dist(R, vector<int>(C, INF));
  using P = pair<int, pair<int, int>>;
  priority_queue<P, vector<P>, greater<P>> pq;

  dist[0][0] = 0;
  pq.push({0, {0, 0}});

  while (!pq.empty()) {
    auto [cost, zahyo] = pq.top();
    auto [r, c] = zahyo;
    pq.pop();

    if (dist[r][c] < cost) continue;

    if (c < C - 1 && cost + A[r][c] < dist[r][c + 1]) {
      dist[r][c + 1] = cost + A[r][c];
      pq.push({dist[r][c + 1], {r, c + 1}});
    }
    if (0 < c && cost + A[r][c - 1] < dist[r][c - 1]) {
      dist[r][c - 1] = cost + A[r][c - 1];
      pq.push({dist[r][c - 1], {r, c - 1}});
    }
    if (r < R - 1 && cost + B[r][c] < dist[r + 1][c]) {
      dist[r + 1][c] = cost + B[r][c];
      pq.push({dist[r + 1][c], {r + 1, c}});
    }
    for (int i = 1; i <= r; i++) {
      if (cost + 1 + i < dist[r - i][c]) {
        dist[r - i][c] = cost + i + 1;
        pq.push({dist[r - i][c], {r - i, c}});
      }
    }
  }

  cout << dist[R - 1][C - 1] << endl;
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
