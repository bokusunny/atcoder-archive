#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    if (a == b) {
      cnt++;
      if (cnt == 3) {
        cout << "Yes" << endl;
        return 0;
      }
    } else {
      cnt = 0;
    }
  }

  cout << "No" << endl;

  return 0;
}
