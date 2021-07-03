#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<vector<int>> A(5001, vector<int>(5001));
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    A[a][b]++;
  }
  vector<vector<int>> S(5002, vector<int>(5002));
  for (int i = 0; i < 5001; i++) {
    for (int j = 0; j < 5001; j++) {
      S[i + 1][j + 1] = S[i + 1][j] + S[i][j + 1] - S[i][j] + A[i][j];
    }
  }

  int ans = 0;
  K++;
  for (int i = 0; i <= 5001 - K; i++) {
    for (int j = 0; j <= 5001 - K; j++) {
      int tmp = S[i + K][j + K] - S[i][j + K] - S[i + K][j] + S[i][j];
      ans = max(ans, tmp);
    }
  }

  cout << ans << endl;

  return 0;
}
