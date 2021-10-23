#include <bits/stdc++.h>
using namespace std;

auto is_icchokusen = [](pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3) {
  long long x1 = p1.first - p2.first;
  long long y1 = p1.second - p2.second;
  long long x2 = p1.first - p3.first;
  long long y2 = p1.second - p3.second;
  return x1 * y2 == x2 * y1;
};

void solve() {
  int N;
  cin >> N;
  vector<pair<long long, long long>> P(N);
  for (int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;
  int cnt = 0;
  for (int a = 0; a < N; a++) {
    for (int b = a + 1; b < N; b++) {
      for (int c = b + 1; c < N; c++) {
        if (!is_icchokusen(P[a], P[b], P[c])) cnt++;
      }
    }
  }

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
