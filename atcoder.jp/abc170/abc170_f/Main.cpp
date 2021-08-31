#include <bits/stdc++.h>
using namespace std;

void solve() {
  int H, W, K;
  cin >> H >> W >> K;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x1--, y1--, x2--, y2--;
  vector<string> C(H);
  for (int i = 0; i < H; i++) cin >> C[i];

  const int INF = 1 << 30;
  vector Dist(H, vector<int>(W, INF));
  queue<pair<int, int>> q;
  Dist[x1][y1] = 0;
  q.emplace(x1, y1);
  vector<int> Dx = {1, 0, -1, 0};
  vector<int> Dy = {0, 1, 0, -1};
  while (!q.empty()) {
    auto [cx, cy] = q.front();
    q.pop();

    if (cx == x2 && cy == y2) {
      cout << Dist[cx][cy] << endl;
      return;
    }

    for (int i = 0; i < 4; i++) {
      for (int d = 1; d <= K; d++) {
        int nx = cx + d * Dx[i];
        int ny = cy + d * Dy[i];
        if (nx < 0 || H <= nx || ny < 0 || W <= ny) break;
        if (C[nx][ny] == '@') break;
        if (Dist[nx][ny] <= Dist[cx][cy]) break;

        if (Dist[nx][ny] == INF) {
          Dist[nx][ny] = Dist[cx][cy] + 1;
          q.emplace(nx, ny);
        }
      }
    }
  }

  cout << -1 << endl;
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
