#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &a : A) cin >> a;

  long long ans = 0;
  long long sequence = 0;
  int prev = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] > prev)
      sequence++;
    else
      ans += (sequence + 1) * sequence / 2, sequence = 1;

    prev = A[i];
  }

  ans += (sequence + 1) * sequence / 2;
  cout << ans << endl;

  return 0;
}
