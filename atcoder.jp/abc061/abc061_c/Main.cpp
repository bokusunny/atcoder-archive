#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  map<int, long long> m;
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    m[A] += B;
  }

  for (auto [val, cnt] : m) {
    K -= cnt;
    if (K <= 0) {
      cout << val << endl;
      return 0;
    }
  }

  return 0;
}
