#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
vi tree_bfs(vvi &edge, int s) {
  int n = (int)edge.size();
  const int INF = 1000000001;
  vi dist(n, INF);
  queue<int> q;
  q.push(s);
  dist.at(s) = 0;

  vi ans_odd;
  vi ans_even;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    if (dist.at(cur) % 2 == 0) {
      ans_even.push_back(cur + 1);
      if ((int)ans_even.size() == n / 2) return ans_even;
    } else {
      ans_odd.push_back(cur + 1);
      if ((int)ans_odd.size() == n / 2) return ans_odd;
    }

    for (auto nxt : edge.at(cur)) {
      if (dist.at(nxt) != INF) continue;

      dist.at(nxt) = dist.at(cur) + 1;
      q.push(nxt);
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> edge(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edge.at(a).push_back(b);
    edge.at(b).push_back(a);
  }

  int s = 0;
  auto ans = tree_bfs(edge, s);

  for (auto a : ans) cout << a << " ";
  cout << endl;

  return 0;
}
