#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<long long> AB(N);
  long long ASum = 0;
  for (int i = 0; i < N; i++) {
    long long a, b;
    cin >> a >> b;
    AB.push_back(a * 2 + b);
    ASum += a;
  }
  sort(AB.begin(), AB.end(), greater<long long>());
  int cnt = 0;
  for (auto ab : AB) {
    ASum -= ab;
    cnt++;
    if (ASum < 0) break;
  }

  cout << cnt << endl;
}

int main() {
  solve();

  return 0;
}
