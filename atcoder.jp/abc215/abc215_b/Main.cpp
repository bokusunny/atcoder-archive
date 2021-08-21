#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long N;
  cin >> N;

  long long ok = 0, ng = 62;
  while (abs(ok - ng) > 1) {
    long long mid = (ok + ng) / 2;
    if (1LL << mid <= N) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << ok << endl;
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
