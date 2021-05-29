#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;

  for (int h = 1; h < 3501; h++) {
    for (int n = 1; n < 3501; n++) {
      if (4 * n * h - N * n - N * h == 0 ||
          (N * n * h % (4 * n * h - N * n - N * h)) != 0) {
        continue;
      }
      int w = (N * n * h) / (4 * n * h - N * n - N * h);
      if (1 <= w && w <= 3500) {
        cout << h << " " << n << " " << w << endl;
        return 0;
      }
    }
  }

  return 0;
}
