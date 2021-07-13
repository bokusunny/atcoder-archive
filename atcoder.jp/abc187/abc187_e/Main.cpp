#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
Graph G;
vector<int> A, B, Depth;
vector<long long> diff, ans;

void dfs1(int u, int p = -1) {
  for (auto v : G[u]) {
    if (v == p) continue;

    Depth[v] = Depth[u] + 1;
    dfs1(v, u);
  }
}

void dfs2(int u, int p = -1) {
  if (p == -1) {
    ans[u] = diff[u];
  } else {
    ans[u] = ans[p] + diff[u];
  }

  for (auto v : G[u]) {
    if (v == p) continue;

    dfs2(v, u);
  }
}

int main() {
  int N;
  cin >> N;
  G.resize(N), A.resize(N - 1), B.resize(N - 1), diff.resize(N), Depth.resize(N), ans.resize(N);
  for (int i = 0; i < N - 1; i++) {
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }

  dfs1(0);

  int Q;
  cin >> Q;
  while (Q--) {
    int t, e, x;
    cin >> t >> e >> x;
    e--;
    auto a = A[e], b = B[e];
    if (t == 1) {
      if (Depth[a] < Depth[b]) {
        diff[0] += x;
        diff[b] -= x;
      } else {
        diff[a] += x;
      }
    } else {
      if (Depth[b] < Depth[a]) {
        diff[0] += x;
        diff[a] -= x;
      } else {
        diff[b] += x;
      }
    }
  }

  dfs2(0);

  for (auto p : ans) cout << p << endl;

  return 0;
}
