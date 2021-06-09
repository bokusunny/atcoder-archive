#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  long long weight;
  Edge(int t, long long w) : to(t), weight(w) {}
};
using WeightGraph = vector<vector<Edge>>;
const long long INF = 1LL << 60;

auto dijkstra(WeightGraph &graph, int s) {
  int n = (int)graph.size();
  vector<long long> dist(n, INF);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> h;
  h.push({0, s});
  dist.at(s) = 0;

  while (!h.empty()) {
    long long dis_s_to_cur;
    int cur;
    tie(dis_s_to_cur, cur) = h.top();
    h.pop();

    if (dis_s_to_cur > dist.at(cur)) continue;

    for (auto edge : graph.at(cur)) {
      long long dis_s_to_nxt = dis_s_to_cur + edge.weight;
      if (dis_s_to_nxt >= dist.at(edge.to)) continue;

      dist.at(edge.to) = dis_s_to_nxt;
      h.push(make_pair(dis_s_to_nxt, edge.to));
    }
  }

  return dist;
}

int main() {
  int n, m;
  cin >> n >> m;

  WeightGraph graph(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;

    graph.at(a).push_back(Edge(b, c));
    graph.at(b).push_back(Edge(a, c));
  }

  auto dist_from_0 = dijkstra(graph, 0);
  auto dist_from_n = dijkstra(graph, n - 1);

  for (int i = 0; i < n; i++) {
    cout << dist_from_0.at(i) + dist_from_n.at(i) << endl;
  }

  return 0;
}
