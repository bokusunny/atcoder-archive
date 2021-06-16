#include <bits/stdc++.h>
using namespace std;

auto convert_base(string xs, int from_base, int to_base) {
  if (xs == "0") return xs;

  long long base_10 = 0;
  long long from_base_multiple = 1LL;
  for (int i = xs.size() - 1; i >= 0; i--) {
    base_10 += (xs.at(i) - '0') * from_base_multiple;
    from_base_multiple *= from_base;
  }

  string res = "";
  while (base_10 > 0) {
    int c = base_10 % to_base == 8 ? 5 : base_10 % to_base;
    res = to_string(c) + res;
    base_10 /= to_base;
  }

  return res;
}

int main() {
  string n;
  cin >> n;
  int k;
  cin >> k;

  while (k--) {
    n = convert_base(n, 8, 9);
  }

  cout << n << endl;

  return 0;
}
