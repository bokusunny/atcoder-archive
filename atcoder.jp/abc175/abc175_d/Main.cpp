#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
 private:
  vector<int> par_table;
  vector<int> size_table;
  int _n;

 public:
  UnionFind(int n) : par_table(n, 0), size_table(n, 1), _n(n) {
    for (int i = 0; i < n; i++) par_table.at(i) = i;
  }

  int find(int x) {
    assert(0 <= x && x < _n);

    if (par_table.at(x) == x) return x;
    return par_table.at(x) = find(par_table.at(x));
  }

  void unite(int x, int y) {
    assert(0 <= x && x < _n);
    assert(0 <= y && y < _n);

    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return;
    if (size_table.at(rx) < size_table.at(ry)) swap(rx, ry);
    size_table.at(rx) += size_table.at(ry);
    par_table.at(ry) = rx;
  }

  bool same(int x, int y) {
    assert(0 <= x && x < _n);
    assert(0 <= y && y < _n);

    int rx = find(x);
    int ry = find(y);
    return rx == ry;
  }

  int size(int x) {
    assert(0 <= x && x < _n);

    return size_table.at(find(x));
  }

  vector<vector<int>> groups() {
    vector<vector<int>> res(_n);
    for (int i = 0; i < _n; i++) res[par_table[i]].push_back(i);

    auto itr = remove_if(res.begin(), res.end(), [](vector<int> v) { return v.empty(); });
    res.erase(itr, res.end());

    return res;
  }
};

int N, K;
const long long INF = 1LL << 62;
vector<long long> P, C;

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

long long calc(vector<int> g) {
  int sz = g.size();
  vector<long long> dp(sz + 1, -INF);
  dp[0] = 0;
  for (auto s : g) {
    int now = s;
    long long score = 0;
    for (int i = 1; i <= sz; i++) {
      now = P[now];
      score += C[now];
      chmax(dp[i], score);
    }
  }

  long long res = -INF;
  if (K <= sz || dp[sz] <= 0) {
    for (int i = 1; i <= min(K, sz); i++) {
      chmax(res, dp[i]);
    };
  } else {
    for (int i = 1; i <= sz; i++) {
      chmax(res, dp[i] + dp[sz] * ((K - i) / sz));
    }
  }

  return res;
}

void solve() {
  UnionFind d(N);
  vector<bool> seen(N);
  for (int s = 0; s < N; s++) {
    int now = s;
    for (int j = 0; j < N; j++) {
      d.unite(now, P[now]);
      now = P[now];
      if (now == s) break;
    }
  }

  auto groups = d.groups();
  long long ans = -INF;
  for (auto g : groups) chmax(ans, calc(g));

  cout << ans << endl;
}

void cinout() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N >> K;
  P.resize(N), C.resize(N);
  for (int i = 0; i < N; i++) cin >> P[i], P[i]--;
  for (int i = 0; i < N; i++) cin >> C[i];
}

int main() {
  cinout();
  solve();

  return 0;
}
