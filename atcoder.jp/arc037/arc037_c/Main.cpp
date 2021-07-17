#include <bits/stdc++.h>
using namespace std;

long long N, K;
vector<long long> A, B;
long long get_cnt(long long x) {
  long long cnt = 0;
  for (auto a : A) {
    int ok = -1, ng = N;

    while (abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;
      if (a * B[mid] <= x) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    cnt += ok + 1;
  }

  return cnt;
}

int main() {
  cin >> N >> K;
  A.resize(N), B.resize(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  sort(B.begin(), B.end());

  long long ng = -1, ok = 1LL << 62;

  while (abs(ok - ng) > 1) {
    long long mid = (ok + ng) / 2;
    if (get_cnt(mid) >= K) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << ok << endl;

  return 0;
}
