#include <bits/stdc++.h>
using namespace std;

template <class T>
T my_pow(T a, T n) {
  T res = 1;
  while (n > 0) {
    if (n & 1) res = res * a;
    a = a * a;
    n >>= 1;
  }
  return res;
}

int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;

  vector<int> L(n);
  for (auto& l : L) cin >> l;

  const long long INF = 1LL << 60;
  long long ans = INF;
  for (int i = 0; i < 1 << n; i++) {
    vector<int> used;
    for (int j = 0; j < n; j++) {
      if (i >> j & 1) used.push_back(L.at(j));
    }
    int used_size = (int)used.size();
    if (used_size < 3) continue;

    assert(3 <= used_size && used_size <= n);

    for (int j = 0; j < my_pow(3, used_size); j++) {
      vector<int> A;
      vector<int> B;
      vector<int> C;
      long long tmp = 0;
      int copy_j = j;
      for (int k = 0; k < used_size; k++) {
        if (copy_j % 3 == 0) {
          A.push_back(used.at(k));
        } else if (copy_j % 3 == 1) {
          B.push_back(used.at(k));
        } else {
          C.push_back(used.at(k));
        }
        copy_j /= 3;
      }
      if (A.empty() || B.empty() || C.empty()) continue;
      tmp += 10 * ((int)A.size() - 1);
      tmp += 10 * ((int)B.size() - 1);
      tmp += 10 * ((int)C.size() - 1);
      tmp += abs(a - accumulate(A.begin(), A.end(), 0));
      tmp += abs(b - accumulate(B.begin(), B.end(), 0));
      tmp += abs(c - accumulate(C.begin(), C.end(), 0));
      if (tmp < ans) ans = tmp;
    }
  }

  cout << ans << endl;

  return 0;
}
