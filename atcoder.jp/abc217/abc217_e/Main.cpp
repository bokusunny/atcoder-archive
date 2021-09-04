#include <bits/stdc++.h>
using namespace std;

void solve() {
  int Q;
  cin >> Q;
  priority_queue<int, vector<int>, greater<int>> pq1;
  // priority_queue<int, vector<int>, greater<int>> pq1, pq2;
  queue<int> q, empty_q;
  while (Q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      // pq2.push(x);
      q.push(x);
    } else if (t == 2) {
      if (pq1.empty()) {
        auto val = q.front();
        q.pop();
        cout << val << endl;
      } else {
        auto val = pq1.top();
        pq1.pop();
        cout << val << endl;
      }
    } else {
      // if (pq1.empty()) {
      int sz = (int)q.size();
      for (int i = 0; i < sz; i++) {
        auto val = q.front();
        q.pop();
        pq1.push(val);
      }
      //   pq2 = pq1;
      // } else {
      //   pq1 = pq2;
      //   q = empty_q;
      // }
    }
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
