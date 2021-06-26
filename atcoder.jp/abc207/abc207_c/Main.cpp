#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<double> L(N);
  vector<double> R(N);
  for (int i = 0; i < N; i++) {
    int t;
    double l, r;
    cin >> t >> l >> r;
    if (t == 2)
      r -= 0.1;
    else if (t == 3)
      l += 0.1;
    else if (t == 4)
      r -= 0.1, l += 0.1;
    L[i] = l, R[i] = r;
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if ((L[i] <= R[j] && L[j] <= R[i]) || (L[j] <= R[i] && L[i] <= R[j])) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
