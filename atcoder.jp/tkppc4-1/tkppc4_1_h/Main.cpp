#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  long long cost;
  int leave;
  Edge(int t, long long w, int l) : to(t), cost(w), leave(l) {}
};
using WeightGraph = vector<vector<Edge>>;
const long long INF = 1LL << 60;

auto dijkstra(WeightGraph &graph, vector<long long> &interval, int s) {
  int n = (int)graph.size();
  vector<long long> dist(n, INF);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> h;
  h.push({0, s});
  dist.at(s) = 0;

  while (!h.empty()) {
    long long dis_s_to_cur, cur;
    // dis_s_to_curは、curに到着するまでのコスト、乗り換えやインターバルは考慮していない
    tie(dis_s_to_cur, cur) = h.top();
    h.pop();

    if (dis_s_to_cur > dist.at(cur)) continue;

    for (auto edge : graph.at(cur)) {
      long long tmp = dis_s_to_cur + interval.at(cur), dis_s_to_nxt;
      if (tmp % edge.leave == 0) {
        dis_s_to_nxt = tmp + edge.cost;
      } else {
        dis_s_to_nxt = (tmp / edge.leave + 1LL) * edge.leave + edge.cost;
      }
      if (dis_s_to_nxt >= dist.at(edge.to)) continue;

      dist.at(edge.to) = dis_s_to_nxt;
      h.push(make_pair(dis_s_to_nxt, edge.to));
    }
  }

  return dist.at(n - 1);
}

int main() {
  int n, m;
  long long k;
  cin >> n >> m >> k;

  vector<long long> interval(n - 1, 0);
  for (int i = 1; i < n - 1; i++) {
    long long t;
    cin >> t;
    interval.at(i) = t;
  }

  WeightGraph graph(n);
  for (int i = 0; i < m; i++) {
    int a, b, d;
    long long c;
    cin >> a >> b >> c >> d;
    a--, b--;

    // バグりそうなので、to 0, from n-1は追加しない
    if (a != n - 1 && b != 0) graph.at(a).push_back(Edge(b, c, d));
    if (b != n - 1 && a != 0) graph.at(b).push_back(Edge(a, c, d));
  }

  auto cost_to_n = dijkstra(graph, interval, 0);

  if (cost_to_n <= k) {
    cout << cost_to_n << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
