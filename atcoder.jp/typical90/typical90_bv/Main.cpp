#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    ans += (long long)(S[i] - 'a') * (1LL << i);
  }

  cout << ans << endl;

  return 0;
}
