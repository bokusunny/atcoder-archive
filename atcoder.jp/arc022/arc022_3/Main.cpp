#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<set<int>> edge(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edge[a].insert(b);
    edge[b].insert(a);
  }

  auto bfs = [&](int root) {
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(root);
    dist[root] = 0;

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (auto next : edge[cur]) {
        if (dist[next] != -1) continue;
        q.push(next);
        dist[next] = dist[cur] + 1;
      }
    }

    int most_dis = 0;
    int most_dis_node = root;
    for (int i = 0; i < n; i++) {
      if (dist[i] > most_dis) {
        most_dis = dist[i];
        most_dis_node = i;
      }
    }

    return make_pair(most_dis_node, most_dis);
  };

  auto [most_dis_node1, _most_dis1] = bfs(0);
  auto [most_dis_node2, _most_dis2] = bfs(most_dis_node1);

  cout << most_dis_node1 + 1 << " " << most_dis_node2 + 1 << endl;

  return 0;
}
