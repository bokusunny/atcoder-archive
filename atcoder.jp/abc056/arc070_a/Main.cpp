#include <bits/stdc++.h>
using namespace std;

int main() {
  long long X;
  cin >> X;

  long long ok = 0, ng = 1000000001;

  while (abs(ok - ng) > 1) {
    long long mid = (ok + ng) / 2;
    if (mid * (mid + 1) / 2 < X) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << ok + 1 << endl;

  return 0;
}
