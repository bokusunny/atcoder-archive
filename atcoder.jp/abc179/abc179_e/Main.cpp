#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, x, m;
  cin >> n >> x >> m;

  set<long long> seen;
  vector<long long> memo;

  while (true) {
    if (seen.count(x)) break;
    seen.insert(x);
    memo.push_back(x);

    x *= x;
    x %= m;
    n--;
    if (n == 0) {
      cout << accumulate(memo.begin(), memo.end(), 0LL) << endl;
      return 0;
    }
  }

  long long ans = 0;
  // cycleに入る前の部分を合計
  auto itr = find(memo.begin(), memo.end(), x);
  ans += accumulate(memo.begin(), itr, 0LL);

  // cycleの途切れる前を合計
  auto cycle_len = memo.end() - itr;
  n += cycle_len;
  auto cycle = vector<long long>(itr, memo.end());
  auto cycle_sum = accumulate(cycle.begin(), cycle.end(), 0LL);
  auto cycle_cnt = n / cycle_len;
  ans += cycle_cnt * cycle_sum;

  auto amari = n % cycle_cnt;
  ans += accumulate(cycle.begin(), cycle.begin() + amari, 0LL);

  cout << ans << endl;

  return 0;
}
