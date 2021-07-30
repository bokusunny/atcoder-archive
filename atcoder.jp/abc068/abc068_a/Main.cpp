#include <bits/stdc++.h>
using namespace std;

int N;

void cinout() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N;
}

void solve() { cout << "ABC" + to_string(N) << endl; }

int main() {
  cinout();
  solve();

  return 0;
}
