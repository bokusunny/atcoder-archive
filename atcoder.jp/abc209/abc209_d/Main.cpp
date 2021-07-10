#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
Graph G;
vector<bool> seen;
vector<int> Num;
void dfs(int cv, int n) {
  seen[cv] = true;
  Num[cv] = n;

  for (auto nv : G[cv]) {
    if (seen.at(nv)) continue;
    int nxt = n == 0;
    dfs(nv, nxt);
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;

  G.resize(N), seen.resize(N), Num.resize(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(0, 0);

  while (Q--) {
    int c, d;
    cin >> c >> d;
    c--, d--;
    if (Num[c] == Num[d]) {
      cout << "Town" << endl;
    } else {
      cout << "Road" << endl;
    }
  }

  return 0;
}
