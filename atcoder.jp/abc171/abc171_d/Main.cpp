#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;

  vector<int> Cnt(100010);
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    Cnt[a]++;
    sum += a;
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int B, C;
    cin >> B >> C;
    long long diff = 1LL * Cnt[B] * (C - B);
    sum += diff;
    Cnt[C] += Cnt[B];
    Cnt[B] = 0;
    cout << sum << endl;
  }
}

int main() {
  solve();

  return 0;
}
