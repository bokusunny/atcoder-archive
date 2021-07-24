#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<int, int> md, mt;
  for (int i = 0; i < N; i++) {
    int d;
    cin >> d;
    md[d]++;
  }
  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    int t;
    cin >> t;
    mt[t]++;
  }

  for (auto [t, cnt] : mt) {
    md[t] -= cnt;
    if (md[t] < 0) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;

  return 0;
}
