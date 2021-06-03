#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, v;
  cin >> a >> v;
  long long b, w, t;
  cin >> b >> w >> t;

  auto dis = abs(a - b);

  if ((v - w) * t >= dis) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
