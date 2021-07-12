#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[i] = a % 200;
  }

  map<int, vector<int>> seen;

  for (int i = 1; i < 1 << min(N, 8); i++) {
    int tmp = 0;
    vector<int> idx;
    for (int j = 0; j < min(N, 8); j++) {
      if (i >> j & 1) tmp += A[j], tmp %= 200, idx.push_back(j + 1);
    }
    if (seen.count(tmp)) {
      cout << "Yes" << endl;
      cout << (int)seen[tmp].size() << " ";
      for (auto v : seen[tmp]) cout << v << " ";
      cout << endl;
      cout << (int)idx.size() << " ";
      for (auto v : idx) cout << v << " ";
      cout << endl;
      return 0;
    } else {
      seen[tmp] = idx;
    }
  }

  cout << "No" << endl;

  return 0;
}
