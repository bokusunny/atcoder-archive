#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, M;
  cin >> N >> M;
  map<int, vector<int>> P;
  for (int i = 0; i < M; i++) {
    int X, Y;
    cin >> X >> Y;
    P[X].push_back(Y);
  }

  set<int> Possible;
  Possible.insert(N);
  for (auto [X, Ys] : P) {
    set<int> Ok, Ng;
    for (auto Y : Ys) {
      if (Possible.count(Y - 1) || Possible.count(Y + 1)) {
        Ok.insert(Y);
      } else {
        Ng.insert(Y);
      }
    }
    for (auto ng : Ng) Possible.erase(ng);
    for (auto ok : Ok) Possible.insert(ok);
  }

  cout << (int)Possible.size() << endl;
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
