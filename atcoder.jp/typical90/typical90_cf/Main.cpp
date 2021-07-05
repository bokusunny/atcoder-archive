#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  vector<int> C;
  int cnt = 1;
  for (int i = 0; i < N - 1; i++) {
    if (S[i + 1] != S[i]) {
      C.push_back(cnt);
      cnt = 1;
    } else {
      cnt++;
    }
  }
  C.push_back(cnt);

  auto f = [](long long x) { return x * (x + 1) / 2; };

  long long ans = f(N);
  for (auto c : C) ans -= f(c);

  cout << ans << endl;

  return 0;
}
