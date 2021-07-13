#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree>
using namespace atcoder;

using S = long long;  // change if necessary
const long long INF = 1LL << 62;
S op(S a, S b) { return min(a, b); }
S e() { return INF; }

struct Edge {
  int to;
  long long weight;
  Edge(int t, long long w) : to(t), weight(w) {}
};
using WeightGraph = vector<vector<Edge>>;
WeightGraph G;
vector<int> In, Out, E, Parent;  // Edepth := 各edgeの向き先のVDepth
vector<long long> VDepth, EDepth;
int timer = 0;

void euler_tour(int v, int p = -1) {
  In[v] = timer;
  timer++;
  E.push_back(v);
  EDepth.push_back(VDepth[v]);
  Parent[v] = p;

  for (auto [nv, c] : G[v]) {
    if (nv == p) continue;
    VDepth[nv] = VDepth[v] + c;
    euler_tour(nv, v);
  }

  Out[v] = timer;
  timer++;
  E.push_back(-v);
  if (v != 0) EDepth.push_back(VDepth[Parent[v]]);
}

int main() {
  int N;
  cin >> N;
  In.resize(N), Out.resize(N), VDepth.resize(N), Parent.resize(N);
  G.resize(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    G[a].push_back(Edge(b, c));
    G[b].push_back(Edge(a, c));
  }
  euler_tour(0);
  assert((int)E.size() == 2 * N);
  assert((int)EDepth.size() == 2 * N - 1);

  // debug
  // cout << "Parent:" << endl;
  // for (auto p : Parent) cout << p << " ";
  // cout << endl;
  // cout << "In:" << endl;
  // for (auto i : In) cout << i << " ";
  // cout << endl;
  // cout << "Out:" << endl;
  // for (auto o : Out) cout << o << " ";
  // cout << endl;
  // cout << "VDepth:" << endl;
  // for (auto vd : VDepth) cout << vd << " ";
  // cout << endl;
  // cout << "Edge:" << endl;
  // for (auto e : E) cout << e << " ";
  // cout << endl;
  // cout << "Edepth:" << endl;
  // for (auto ev : EDepth) cout << ev << " ";
  // cout << endl;

  segtree<S, op, e> seg(EDepth);
  int Q, K;
  cin >> Q >> K;
  K--;
  while (Q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    auto lca_depth_xk = seg.prod(min(In[x], In[K]), max(In[x], In[K]));
    auto lca_depth_yk = seg.prod(min(In[y], In[K]), max(In[y], In[K]));
    auto dist_xk = VDepth[x] + VDepth[K] - 2 * lca_depth_xk;
    auto dist_yk = VDepth[y] + VDepth[K] - 2 * lca_depth_yk;
    cout << dist_xk + dist_yk << endl;
  }

  return 0;
}
