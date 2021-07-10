#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;

  int sum = 0;
  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;

    if (i % 2 == 1) {
      sum += a;
    } else {
      sum += a - 1;
    }
  }

  if (sum <= X) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
