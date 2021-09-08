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
  const string T = "Takahashi", A = "Aoki";
  auto len = bitlen(N);
  if (len & 1) {
    for (int i = 1; i < len; i++) {
      int pos = len - i - 1;
      if (i & 1) {
        if (N >> pos & 1) continue;
        cout << T << endl;
        return;
      } else {
        if (N >> pos & 1) {
          cout << A << endl;
          return;
        }
      }
    }
    cout << A << endl;
  } else {
    for (int i = 1; i < len; i++) {
      int pos = len - i - 1;
      if (i & 1) {
        if (N >> pos & 1) {
          cout << T << endl;
          return;
        }
      } else {
        if (N >> pos & 1) continue;
        cout << A << endl;
        return;
      }
    }
    cout << T << endl;
  }
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
