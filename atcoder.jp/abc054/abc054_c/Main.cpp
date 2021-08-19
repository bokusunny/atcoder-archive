#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<set<int>> G(N);
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    G[A].insert(B);
    G[B].insert(A);
  }

  auto is_valid = [&](vector<int> v) {
    if (!G[0].count(v[0])) return false;
    for (int i = 0; i < N - 2; i++) {
      if (!G[v[i]].count(v[i + 1])) return false;
    }
    return true;
  };

  vector<int> vec;
  for (int i = 1; i < N; i++) vec.push_back(i);
  int cnt = 0;
  do {
    if (is_valid(vec)) cnt++;
  } while (next_permutation(vec.begin(), vec.end()));

  cout << cnt << endl;
}

void setcin() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  setcin();
  solve();

  return 0;
}
