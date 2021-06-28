#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> A(N);
  for (auto &a : A) cin >> a;

  // K回切った後全部x以下
  // 全部x以下にするのに必要なcut回数がk回以下
  auto is_ok = [&](long long x) {
    long long cnt = 0;
    for (auto a : A) cnt += (a - 1) / x;
    return cnt <= K;
  };

  long long ng = 0, ok = 1000000001;

  while (abs(ok - ng) > 1) {
    long long mid = (ok + ng) / 2;
    if (is_ok(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << ok << endl;

  return 0;
}
