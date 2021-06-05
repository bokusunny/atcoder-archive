#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> M;
  int max = 1;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;

    if (M.count(p - 1)) {
      int val = M.at(p - 1) + 1;
      if (val > max) max = val;
      M[p] = val;
    } else {
      M[p] = 1;
    }
  }

  cout << n - max << endl;

  return 0;
}
