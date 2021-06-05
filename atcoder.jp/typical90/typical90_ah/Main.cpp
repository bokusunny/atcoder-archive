#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (auto &a : A) cin >> a;

  map<int, int> M;

  int ans = 0;
  int streak = 0, type_cnt = 0;

  for (int i = 0; i < n; i++) {
    int a = A.at(i);
    M.count(a) ? M.at(a)++ : M[a] = 1;
    streak++;
    // 新しいtypeの場合
    if (M.at(a) == 1) {
      type_cnt++;
      // typeがk種類を超えた場合
      if (type_cnt > k) {
        while (type_cnt > k) {
          int A_sentou = A.at(i - streak + 1);
          M.at(A_sentou)--;
          streak--;
          if (M.at(A_sentou) == 0) type_cnt--;
        }
      }
    }

    ans = max(ans, streak);
  }

  cout << ans << endl;

  return 0;
}
