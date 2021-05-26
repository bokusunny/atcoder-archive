#include <bits/stdc++.h>
using namespace std;

long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  const long long mod = 998244353;
  int n;
  cin >> n;
  map<int, int> dist;

  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    if ((i == 0 && d != 0) || (i != 0 && d == 0)) {
      cout << 0 << endl;
      return 0;
    }
    dist[d]++;
  }

  long long ans = 1;
  pair<long long, long long> prev(0, 1);
  for (const auto [current_dist, current_dist_node_num] : dist) {
    if (current_dist == 0) continue;
    long long prev_dist, prev_dist_node_num;
    tie(prev_dist, prev_dist_node_num) = prev;
    if (prev_dist + 1 != current_dist) {
      cout << 0 << endl;
      return 0;
    }
    ans = ans * modpow(prev_dist_node_num, current_dist_node_num, mod);
    ans %= mod;

    prev = make_pair(current_dist, current_dist_node_num);
  }

  cout << ans << endl;

  return 0;
}
