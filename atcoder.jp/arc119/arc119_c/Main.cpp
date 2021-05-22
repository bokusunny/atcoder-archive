#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  vector<long long> h(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    if (i % 2) a *= -1;
    h[i] = a;
  }

  vector<long long> s(n + 1, 0);
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + h[i];
  }

  long long ans = 0;
  map<long long, long long> d;
  for (int i = 0; i < n + 1; i++) {
    // 存在しない番地にアクセスした場合、0が帰る
    ans += d[s[i]];
    d[s[i]]++;
  }

  cout << ans << endl;

  return 0;
}
