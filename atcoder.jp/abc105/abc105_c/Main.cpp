#include <bits/stdc++.h>
using namespace std;

template <class T>
T mod_minus(T val, T m) {
  T res = val % m;
  if (res < 0) m > 0 ? res += m : res -= m;
  return res;
}

string solve(long long x) {
  if (x == 0) return "0";

  string res = "";
  while (x != 0) {
    res = to_string(mod_minus(x, -2LL)) + res;
    x > 0 || x % (-2) == 0 ? x /= (-2) : x = x / (-2) + 1;
  }

  return res;
}

int main() {
  long long n;
  cin >> n;

  cout << solve(n) << endl;

  return 0;
}
