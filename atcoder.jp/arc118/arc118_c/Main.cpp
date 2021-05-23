#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  int n;
  cin >> n;

  vector<int> A;

  for (int i = 2; i < 10001; i++) {
    if (i % 6 == 0 || i % 10 == 0 || i % 15 == 0) {
      if (i == 12) continue;
      A.push_back(i);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;

  return 0;
}
