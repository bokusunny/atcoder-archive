#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
vector<int> In, Out, VDepth, Edge, EDepth, Parent;  // Edepth := 各edgeの向き先のVDepth
int timer = 0;

void euler_tour(Graph &G, int v, int p = -1) {
  In[v] = timer;
  timer++;
  Edge.push_back(v);
  EDepth.push_back(VDepth[v]);
  Parent[v] = p;

  for (auto nv : G[v]) {
    if (nv == p) continue;
    VDepth[nv] = VDepth[v] + 1;
    euler_tour(G, nv, v);
  }

  Out[v] = timer;
  timer++;
  Edge.push_back(-v);
  if (v != 0) EDepth.push_back(VDepth[Parent[v]]);
}

const int INF = 1 << 30;
struct SegTree {
 private:
  int n;
  vector<int> node;

 public:
  SegTree(vector<int> v) {
    int sz = (int)v.size();
    n = 1;
    while (n < sz) n *= 2;
    node.resize(2 * n - 1, INF);
    for (int i = 0; i < sz; i++) node.at(i + n - 1) = v.at(i);
    for (int i = n - 2; i >= 0; i--) node.at(i) = min(node.at(2 * i + 1), node.at(2 * i + 2));
  }

  void update(int x, int val) {
    x += n - 1;
    node.at(x) = val;
    while (x > 0) {
      x = (x - 1) / 2;
      node.at(x) = min(node.at(2 * x + 1), node.at(2 * x + 2));
    }
  }

  // [l, r): 要求区間
  // k: 自分が今いるノード
  // [a, b): kがカバーする区間
  int get_min(int l, int r, int k = 0, int a = 0, int b = -1) {
    assert(0 <= l && r <= n && l < r);
    if (b == -1) b = n;  // 初期値設定

    if (b <= l || r <= a) return INF;         // 要求区間とカバー区間が交わらない
    if (l <= a && b <= r) return node.at(k);  // 要求区間がカバー区間を完全被覆

    int vl = get_min(l, r, 2 * k + 1, a, (a + b) / 2);
    int vr = get_min(l, r, 2 * k + 2, (a + b) / 2, b);
    return min(vl, vr);
  }
};

int main() {
  int N;
  cin >> N;
  In.resize(N), Out.resize(N), VDepth.resize(N), Parent.resize(N);
  Graph G(N);
  for (int i = 0; i < N - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  euler_tour(G, 0);
  assert((int)Edge.size() == 2 * N);
  assert((int)EDepth.size() == 2 * N - 1);

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
  // for (auto e : Edge) cout << e << " ";
  // cout << endl;
  // cout << "Edepth:" << endl;
  // for (auto ev : EDepth) cout << ev << " ";
  // cout << endl;

  SegTree seg(EDepth);
  int Q;
  cin >> Q;
  while (Q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    auto lca_depth = seg.get_min(min(In[a], In[b]), max(In[a], In[b]));
    cout << VDepth[a] + VDepth[b] - 2 * lca_depth + 1 << endl;
  }

  return 0;
}
