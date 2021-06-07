#include <bits/stdc++.h>
using namespace std;

int digsum(int n) {
  int res = 0;
  while (n > 0) {
    res += n % 10;
    n /= 10;
  }

  return res;
}

int calc_next_num(int x) {
  auto y = digsum(x);
  auto z = (x + y) % 100000;
  return z;
}

int main() {
  int n;
  long long k;
  cin >> n >> k;
  // スイッチを何回押したタイミングでその数字が初めて現れたか
  map<int, int> first_emerge_memo;
  int cnt = 0;
  first_emerge_memo[n] = cnt;
  vector<int> val_memo = {n};

  int cicle;
  while (true) {
    n = calc_next_num(n);
    val_memo.push_back(n);
    cnt++;
    if (cnt == k) {
      cout << n << endl;
      return 0;
    }

    if (first_emerge_memo.count(n)) {
      cicle = cnt - first_emerge_memo.at(n);
      break;
    } else {
      first_emerge_memo[n] = cnt;
    }
  }

  // 周期性が発見された場合、k回目がサイクルの何番目か
  long long left = (k - (cnt - 1)) % cicle;
  int i = left == 0 ? cicle - 1 : left - 1;

  cout << val_memo.at(cnt - cicle + i) << endl;

  return 0;
}
