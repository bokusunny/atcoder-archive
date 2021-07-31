#include <bits/stdc++.h>
using namespace std;

int Q;

void solve() {
  cin >> Q;
  using P = pair<long long, int>;
  priority_queue<P, vector<P>, greater<P>> pq;
  vector<long long> bonus(Q + 1);

  for (int i = 1; i <= Q; i++) {
    bonus[i] += bonus[i - 1];
    int p;
    cin >> p;
    if (p == 1) {
      long long X;
      cin >> X;
      pq.emplace(X - bonus[i], i);
    } else if (p == 2) {
      long long X;
      cin >> X;
      bonus[i] += X;
    } else {
      auto [val, t] = pq.top();
      pq.pop();

      cout << val + bonus[i] << endl;
    }
  }
}

void cinout() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

int main() {
  cinout();
  solve();

  return 0;
}
