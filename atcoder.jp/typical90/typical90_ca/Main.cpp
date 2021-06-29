#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W)), B(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> B[i][j];
    }
  }

  long long ans = 0;
  for (int i = 0; i < H - 1; i++) {
    for (int j = 0; j < W - 1; j++) {
      auto diff = B[i][j] - A[i][j];
      ans += abs(diff);
      A[i][j] += diff, A[i + 1][j] += diff, A[i][j + 1] += diff, A[i + 1][j + 1] += diff;
    }
    if (A[i][W - 1] != B[i][W - 1]) {
      cout << "No" << endl;
      return 0;
    }
  }

  for (int i = 0; i < W; i++) {
    if (A[H - 1][i] != B[H - 1][i]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  cout << ans << endl;

  return 0;
}
