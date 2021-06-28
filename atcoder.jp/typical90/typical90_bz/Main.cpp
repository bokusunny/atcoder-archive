#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int main() {
  int N, M;
  cin >> N >> M;
  Graph G(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a > b)
      G[a].push_back(b);
    else
      G[b].push_back(a);
  }

  int ans = 0;
  for (auto v : G)
    if ((int)v.size() == 1) ans++;

  cout << ans << endl;

  return 0;
}
