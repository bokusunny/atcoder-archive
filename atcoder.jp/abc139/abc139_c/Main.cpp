#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> H(n);
  for (auto &h : H) cin >> h;

  int max = 0;
  int tmp = 0;
  for (int i = 0; i < n - 1; i++) {
    if (H.at(i) >= H.at(i + 1)) {
      tmp++;
    } else {
      if (tmp > max) max = tmp;
      tmp = 0;
    }
  }

  if (tmp > max) max = tmp;

  cout << max << endl;

  return 0;
}
