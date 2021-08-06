#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;

void solve() {
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  long long ans = 0;
  int xor_sum = 0, sum = 0;
  int l = 0, r = 0;
  while (r < N) {
    r++;
    xor_sum ^= A[r - 1];
    sum += A[r - 1];
    if (xor_sum != sum) {
      while (l < r && xor_sum != sum) {
        l++;
        xor_sum ^= A[l - 1];
        sum -= A[l - 1];
      }
    }
    ans += r - l;
  }

  cout << ans << endl;
}

int main() {
  solve();

  return 0;
}
