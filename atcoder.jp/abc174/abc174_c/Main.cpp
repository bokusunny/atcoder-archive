#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  cin >> K;

  vector<int> A(K + 1);
  A[0] = 7 % K;
  for (int i = 1; i <= K; i++) {
    if (A[i - 1] == 0) {
      cout << i << endl;
      return 0;
    }
    A[i] = (10 * A[i - 1] + 7) % K;
  }

  cout << -1 << endl;

  return 0;
}
