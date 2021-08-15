#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<pair<int, int>> LR(N);
  map<int, vector<int>> VR;
  for (int i = 0; i < N; i++) {
    cin >> LR[i].first >> LR[i].second;
    VR[LR[i].first].push_back(LR[i].second);
  }
  sort(LR.begin(), LR.end());

  priority_queue<int, vector<int>, greater<int>> pq;

  int seen_cnt = 0, L = 0;
  while (seen_cnt < N) {
    if (pq.empty()) {
      L = LR[seen_cnt].first;
    }
    for (auto R : VR[L]) pq.push(R);

    auto R = pq.top();
    pq.pop();
    if (R < L) {
      cout << "No" << endl;
      return;
    }
    seen_cnt++;
    L++;
  }

  cout << "Yes" << endl;
}

void setcin() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  setcin();

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}
