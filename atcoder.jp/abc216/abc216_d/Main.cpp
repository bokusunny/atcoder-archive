#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<deque<int>> T(M);
  for (int i = 0; i < M; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int a;
      cin >> a;
      a--;
      T[i].push_back(a);
    }
  }

  vector<int> Num(N, -1);  // i色のボールが一番上にある場合何番目の筒にあるか
  queue<pair<int, int>> q;
  for (int i = 0; i < M; i++) {
    auto col = T[i].front();
    if (Num[col] == -1) {
      Num[col] = i;
    } else {
      T[Num[col]].pop_front();
      T[i].pop_front();
      q.emplace(Num[col], i);
    }
  }

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    if (!T[i].empty()) {
      auto col1 = T[i].front();
      if (Num[col1] == -1) {
        Num[col1] = i;
      } else {
        T[Num[col1]].pop_front();
        T[i].pop_front();
        q.emplace(Num[col1], i);
      }
    }
    if (!T[j].empty()) {
      auto col1 = T[j].front();
      if (Num[col1] == -1) {
        Num[col1] = j;
      } else {
        T[Num[col1]].pop_front();
        T[j].pop_front();
        q.emplace(Num[col1], j);
      }
    }
  }

  for (auto &d : T) {
    if (!d.empty()) {
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
