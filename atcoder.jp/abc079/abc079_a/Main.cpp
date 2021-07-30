#include <bits/stdc++.h>
using namespace std;

string N;

void cinout() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N;
}

void solve() {
  int p1 = -1, p2 = -1;
  for (int i = 0; i < (int)N.size(); i++) {
    if (p1 == p2 && p1 == N[i]) {
      cout << "Yes" << endl;
      return;
    }
    p2 = p1, p1 = N[i];
  }
  cout << "No" << endl;
}

int main() {
  cinout();
  solve();

  return 0;
}
