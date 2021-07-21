#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<vector<long long>> cnt(10, vector<long long>(10));
  for (int i = 1; i <= N; i++) {
    int top = to_string(i)[0] - '0';
    int bottom = i % 10;
    cnt[top][bottom]++;
  }

  long long ans = 0;
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      ans += cnt[i][j] * cnt[j][i];
    }
  }

  cout << ans << endl;

  return 0;
}
