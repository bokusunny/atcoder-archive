#include <bits/stdc++.h>
using namespace std;

void solve() {
  int H, W, N;
  cin >> H >> W >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  auto a = A;
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  auto b = B;
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());

  for (int i = 0; i < N; i++) {
    auto ai = lower_bound(a.begin(), a.end(), A[i]) - a.begin() + 1;
    auto bi = lower_bound(b.begin(), b.end(), B[i]) - b.begin() + 1;
    cout << ai << " " << bi << endl;
  }
}

int main() {
  solve();

  return 0;
}
