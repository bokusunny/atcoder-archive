#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k, s;
  cin >> n >> k >> s;

  for (int i = 0; i < k; i++) {
    cout << s << " ";
  }

  for (int i = 0; i < n - k; i++) {
    if (s == 1000000000) {
      cout << 1 << " ";
    } else {
      cout << s + 1 << " ";
    }
  }

  cout << endl;

  return 0;
}
