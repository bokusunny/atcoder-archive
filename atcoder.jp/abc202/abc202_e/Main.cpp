#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
vector<vector<int>> li;
vector<int> In, Out, Depth;
int t = 0;

void dfs(Graph &G, int v) {
  In[v] = t;
  t++;
  li[Depth[v]].push_back(In[v]);
  for (auto nv : G[v]) {
    Depth[nv] = Depth[v] + 1;
    dfs(G, nv);
  }
  Out[v] = t;
  t++;
}

int main() {
  int N;
  cin >> N;
  Graph G(N);
  for (int i = 1; i < N; i++) {
    int p;
    cin >> p;
    p--;
    G[p].push_back(i);
  }

  In.resize(N), Out.resize(N), Depth.resize(N), li.resize(N);
  dfs(G, 0);

  // for (auto i : In) cout << i << " ";
  // cout << endl;
  // for (auto o : Out) cout << o << " ";

  int Q;
  cin >> Q;
  while (Q--) {
    int U, D;
    cin >> U >> D;
    U--;
    cout << lower_bound(li[D].begin(), li[D].end(), Out[U]) - lower_bound(li[D].begin(), li[D].end(), In[U]) << endl;
  }

  return 0;
}
