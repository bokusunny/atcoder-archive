#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  vector<long long> A;
  long long zero_cnt = 0;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    if (a == 0) {
      zero_cnt++;
    } else {
      A.push_back(a);
    }
  }
  n = (long long)A.size();
  long long zero_prod_cnt = zero_cnt * n + zero_cnt * (zero_cnt - 1) / 2;
  sort(A.begin(), A.end());

  // x以下のA[i]*A[j]の個数はk個以上か？
  auto is_ok = [&](long long x) {
    long long cnt = 0;
    for (auto a : A) {
      if (a > 0) {
        long long ok = -1, ng = n;

        while (abs(ok - ng) > 1) {
          long long mid = (ok + ng) / 2;
          if (a * A.at(mid) <= x) {
            ok = mid;
          } else {
            ng = mid;
          }
        }
        cnt += ok + 1;
      } else {
        long long ng = -1, ok = n;

        while (abs(ok - ng) > 1) {
          long long mid = (ok + ng) / 2;
          if (a * A.at(mid) <= x) {
            ok = mid;
          } else {
            ng = mid;
          }
        }
        cnt += n - ok;
      }
      if (a * a <= x) cnt--;
    }
    cnt /= 2;
    if (x >= 0) cnt += zero_prod_cnt;

    return cnt >= k;
  };

  const long long INF = 1LL << 60;
  long long ng = -INF, ok = INF;

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
