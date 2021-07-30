#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> H;

void cinout() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N;
  H.resize(N);
  for (int i = 0; i < N; i++) cin >> H[i];
}

void solve() {
  H[0]--;
  for (int i = 1; i < N; i++) {
    if (H[i] < H[i - 1]) {
      cout << "No" << endl;
      return;
    } else if (H[i] > H[i - 1]) {
      H[i]--;
    }
  }
  cout << "Yes" << endl;
}

int main() {
  cinout();
  solve();

  return 0;
}
