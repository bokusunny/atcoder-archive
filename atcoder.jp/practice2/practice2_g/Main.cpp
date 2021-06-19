#include <bits/stdc++.h>
using namespace std;

#include <atcoder/scc>
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  scc_graph G(n);
  for (int i = 0; i < m; i++) {
    int s, t;
    cin >> s >> t;
    G.add_edge(s, t);
  }

  auto scc = G.scc();

  cout << (int)scc.size() << endl;
  for (auto vs : scc) {
    cout << (int)vs.size();
    for (auto v : vs) {
      cout << " " << v;
    }
    cout << endl;
  }

  return 0;
}
