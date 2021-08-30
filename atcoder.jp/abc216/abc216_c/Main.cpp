#include <bits/stdc++.h>
using namespace std;

template <class T>
int bitlen(T n) {
  int res = 0;
  while (n > 0) {
    res++;
    n >>= 1;
  }
  return res;
}

void solve() {
  long long N;
  cin >> N;
  auto len = bitlen(N);

  string ans;
  for (int i = len - 1; i >= 0; i--) {
    if (N >> i & 1) {
      ans += "BA";
    } else {
      ans += "B";
    }
  }

  cout << ans << endl;
}

void setcin() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  setcin();
  solve();

  return 0;
}
