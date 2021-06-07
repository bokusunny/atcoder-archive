#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
auto tree_bfs(Graph &graph, int s) {
  int n = (int)graph.size();
  const int INF = 1000000001;
  vector<int> dist(n, INF);
  queue<int> q;
  q.push(s);
  dist.at(s) = 0;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    for (auto nxt : graph.at(cur)) {
      if (dist.at(nxt) != INF) continue;

      dist.at(nxt) = dist.at(cur) + 1;
      q.push(nxt);
    }
  }

  int most_dis = 0;
  int most_dis_node = s;
  for (int i = 0; i < n; i++) {
    if (dist.at(i) > most_dis) {
      most_dis = dist.at(i);
      most_dis_node = i;
    }
  }

  return make_pair(most_dis, most_dis_node);
}

auto calc_tree_chokkei(Graph &graph) {
  const int s = 0;  // 任意
  auto [most_dis1, most_dis_node1] = tree_bfs(graph, s);
  auto [most_dis2, most_dis_node2] = tree_bfs(graph, most_dis_node1);

  return most_dis2;
}

int main() {
  int n;
  cin >> n;
  Graph graph(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
  }

  auto chokkei = calc_tree_chokkei(graph);

  if (chokkei % 3 == 1) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }

  return 0;
}
