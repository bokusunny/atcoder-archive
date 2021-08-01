#include <bits/stdc++.h>
using namespace std;

string S;
int K;

void solve() {
  cin >> S >> K;
  using T = tuple<string, int, int>;
  priority_queue<T, vector<T>, greater<T>> pq;
  for (int i = 0; i < (int)S.size(); i++) {
    pq.emplace(S.substr(i, 1), i, i + 1);
  }

  set<string> seen;
  while (1) {
    auto [str, l, r] = pq.top();
    pq.pop();

    if (r + 1 <= (int)S.size()) pq.emplace(S.substr(l, r + 1 - l), l, r + 1);
    if (seen.count(str)) continue;

    K--;
    if (K == 0) {
      cout << str << endl;
      return;
    }
    seen.insert(str);
  }
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
