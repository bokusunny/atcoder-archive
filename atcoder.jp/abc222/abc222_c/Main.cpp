#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, M;
  cin >> N >> M;
  vector A(2 * N, vector<int>(M));
  for (int i = 0; i < 2 * N; i++) {
    for (int j = 0; j < M; j++) {
      char a;
      cin >> a;
      if (a == 'G') {
        A[i][j] = 0;
      } else if (a == 'C') {
        A[i][j] = 1;
      } else {
        A[i][j] = 2;
      }
    }
  }

  using P = pair<int, int>;
  priority_queue<P, vector<P>, less<P>> pq;
  for (int i = 0; i < 2 * N; i++) {
    pq.emplace(0, -i);
  }

  for (int m = 0; m < M; m++) {
    priority_queue<P, vector<P>, less<P>> pq2;
    for (int j = 0; j < N; j++) {
      auto [cnt1, i1] = pq.top();
      pq.pop();
      auto [cnt2, i2] = pq.top();
      pq.pop();
      if (A[-i1][m] == A[-i2][m]) {
        pq2.emplace(cnt1, i1);
        pq2.emplace(cnt2, i2);
      } else if (A[-i1][m] - A[-i2][m] == 1 || (A[-i1][m] == 0 && A[-i2][m] == 2)) {
        // i1が負ける
        pq2.emplace(cnt1, i1);
        pq2.emplace(cnt2 + 1, i2);
      } else {
        pq2.emplace(cnt1 + 1, i1);
        pq2.emplace(cnt2, i2);
      }
    }
    assert((int)pq2.size() == 2 * N);
    swap(pq, pq2);
  }

  for (int i = 0; i < 2 * N; i++) {
    auto [cnt, j] = pq.top();
    pq.pop();
    cout << -j + 1 << endl;
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
