#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long ans = 0;
  for (int a = 1; a < N; a++) {
    ans += (N - 1) / a;
  }

  cout << ans << endl;

  return 0;
}
