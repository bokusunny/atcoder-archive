#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  vector<long long> A(N);
  for (auto &a : A) cin >> a;

  long long x = 0;
  for (int i = 0; i < N; i++) {
    i % 2 == 0 ? x += A[i] : x -= A[i];
  }

  cout << x;
  auto tmp = x / 2;
  for (int i = 0; i < N - 1; i++) {
    tmp = A[i] - tmp;
    cout << " " << 2 * tmp;
  }
  cout << endl;

  return 0;
}
