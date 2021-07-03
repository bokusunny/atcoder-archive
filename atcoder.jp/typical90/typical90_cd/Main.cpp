#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

template <class T>
T my_pow(T a, T n) {
  assert(n >= 0);
  T res = 1;
  while (n > 0) {
    if (n & 1) res = res * a;
    a = a * a;
    n >>= 1;
  }
  return res;
}

// 二つの数は同じ桁
mint get_sum(long long l, long long r) {
  mint res = (r + l);
  res *= (r - l + 1);
  res /= 2;
  res *= (int)to_string(l).size();
  return res;
}

int main() {
  long long L, R;
  cin >> L >> R;
  int LSize = (int)to_string(L).size(), RSize = (int)to_string(R).size();

  mint ans = 0;
  if (LSize == RSize) {
    ans += get_sum(L, R);
  } else {
    ans += get_sum(L, my_pow(10LL, (long long)LSize) - 1);
    for (long long i = LSize + 1; i < RSize; i++) {
      ans += get_sum(my_pow(10LL, i - 1LL), my_pow(10LL, i) - 1LL);
    }
    ans += get_sum(my_pow(10LL, (long long)RSize - 1), R);
  }

  cout << ans.val() << endl;

  return 0;
}
