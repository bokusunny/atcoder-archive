#include <bits/stdc++.h>
using namespace std;

int H, W, s, g;

struct Edge {
  int to;
  long long weight;
  Edge(int t, long long w) : to(t), weight(w) {}
};
using WeightGraph = vector<vector<Edge>>;
const long long INF = 1LL << 62;
WeightGraph G;

int to_num(int h, int w) { return h * W + w; }

auto dijkstra(int s, int g) {
  vector<long long> dist(H * W + 52, INF);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> h;
  h.push({0, s});
  dist[s] = 0;

  while (!h.empty()) {
    auto [cd, cv] = h.top();
    h.pop();

    if (cd > dist[cv]) continue;

    for (auto [nv, w] : G[cv]) {
      long long nd = cd + w;
      if (nd >= dist[nv]) continue;

      dist[nv] = nd;
      h.push({nd, nv});
    }
  }

  if (dist[g] == INF) {
    cout << -1 << endl;
  } else {
    cout << dist[g] << endl;
  }
}

int main() {
  cin >> H >> W;
  G.resize(H * W + 52);
  map<char, int> M;

  vector<vector<char>> grid(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < 26; i++) {
    int fr = H * W + i;
    int to = fr + 26;
    G[fr].push_back({to, 1});
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      auto c = grid[i][j];
      auto node = to_num(i, j);
      if (c == '#') continue;
      if (c == 'S') s = node;
      if (c == 'G') g = node;
      if ('a' <= c && c <= 'z') {
        G[node].emplace_back(H * W + c - 'a', 0);
        G[H * W + 26 + c - 'a'].emplace_back(node, 0);
      }
      if (i != H - 1 && grid[i + 1][j] != '#') {
        auto node2 = to_num(i + 1, j);
        G[node].push_back({node2, 1});
        G[node2].push_back({node, 1});
      }
      if (j != W - 1 && grid[i][j + 1] != '#') {
        auto node2 = to_num(i, j + 1);
        G[node].push_back({node2, 1});
        G[node2].push_back({node, 1});
      }
    }
  }

  dijkstra(s, g);

  return 0;
}
