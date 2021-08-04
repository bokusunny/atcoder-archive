#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> AB;

void solve() {
  cin >> N;
  AB.resize(N);
  for (int i = 0; i < N; i++) cin >> AB[i].second >> AB[i].first;
  sort(AB.begin(), AB.end());

  int timer = 0;
  for (auto [B, A] : AB) {
    timer += A;
    if (timer > B) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
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
