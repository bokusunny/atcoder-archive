#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int x = X[i] - X[j], y = Y[i] - Y[j];
      if (x == 0)
        continue;
      else if (x > 0) {
        if (x >= y && y >= -x) cnt++;
      } else if (x < 0) {
        if (x <= y && y <= -x) cnt++;
      }
    }
  }

  cout << cnt << endl;

  return 0;
}
