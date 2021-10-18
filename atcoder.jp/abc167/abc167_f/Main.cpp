#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) cin >> S[i];

  vector<pair<int, int>> First, Second;
  for (auto &s : S) {
    int cntl = 0, cntr = 0;
    for (auto &c : s) {
      if (c == '(') {
        cntl++;
      } else {
        if (cntl == 0) {
          cntr++;
        } else {
          cntl--;
        }
      }
    }

    if (cntr > cntl) {
      Second.emplace_back(cntl, cntr);
    } else {
      First.emplace_back(cntl, cntr);
    }
  }
  sort(First.begin(), First.end(), [](auto const &a, auto const &b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
  });
  sort(Second.begin(), Second.end(), [](auto const &a, auto const &b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
  });

  int cnt = 0;
  for (auto [lcnt, rcnt] : First) {
    cnt -= rcnt;
    if (cnt < 0) {
      cout << "No" << endl;
      return;
    }
    cnt += lcnt;
  }
  for (auto [lcnt, rcnt] : Second) {
    cnt -= rcnt;
    if (cnt < 0) {
      cout << "No" << endl;
      return;
    }
    cnt += lcnt;
  }

  if (cnt != 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
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
