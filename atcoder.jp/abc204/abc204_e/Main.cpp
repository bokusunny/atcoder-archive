#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  long long c;
  long long d;
  Edge(int t, long long c, long long d) : to(t), c(c), d(d) {}
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
    long long dis_s_to_cur, cur;
    tie(dis_s_to_cur, cur) = h.top();
    h.pop();

    if (dis_s_to_cur > dist.at(cur)) continue;

    for (auto edge : graph.at(cur)) {
      auto calc_cost = [&]() {
        long long min_cost = dis_s_to_cur + edge.c + edge.d / (dis_s_to_cur + 1LL);
        long long around_optimized_t = (long long)sqrt(edge.d);
        for (long long i = around_optimized_t - 3LL; i <= around_optimized_t + 3LL; i++) {
          if (dis_s_to_cur > i) continue;
          long long tmp = around_optimized_t + edge.c + edge.d / (around_optimized_t + 1LL);
          if (tmp < min_cost) min_cost = tmp;
        }

        return min_cost;
      };
      long long dis_s_to_nxt = calc_cost();
      if (dis_s_to_nxt >= dist.at(edge.to)) continue;

      dist.at(edge.to) = dis_s_to_nxt;
      h.push(make_pair(dis_s_to_nxt, edge.to));
    }
  }

  if (dist.at(n - 1) == INF) {
    cout << -1 << endl;
  } else {
    cout << dist.at(n - 1) << endl;
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  WeightGraph graph(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    long long c, d;
    cin >> c >> d;
    a--, b--;

    graph.at(b).push_back(Edge(a, c, d));
    graph.at(a).push_back(Edge(b, c, d));
  }

  dijkstra(graph, 0);

  return 0;
}
