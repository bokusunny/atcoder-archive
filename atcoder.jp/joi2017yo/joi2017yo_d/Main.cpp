#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> doll_cnt(m, 0);
  vector<int> doll_vec(n);
  vector<vector<int>> sum(m, vector<int>(n + 1, 0));

  for (int i = 0; i < n; i++) {
    int doll_number;
    cin >> doll_number;
    doll_number--;
    doll_cnt[doll_number]++;
    doll_vec[i] = doll_number;
  }

  for (int doll_number = 0; doll_number < m; doll_number++) {
    vector<int>& s = sum[doll_number];
    for (int i = 0; i < n; i++) {
      s[i + 1] = s[i] + (doll_vec[i] == doll_number);
    }
  }

  const int table_count = pow(2, m) + 1;
  const int table_max = pow(10, 5) + 1;
  // dp[i]: ぬいぐるみのbit集合iを左から順に並べるのに必要な最小の手数
  vector<int> dp(table_count, table_max);
  dp[0] = 0;

  for (int i = 0; i < table_count - 1; i++) {
    int already_ordered_doll_cnt = 0;
    for (int j = 0; j < m; j++) {
      if (i >> j & 1) already_ordered_doll_cnt += doll_cnt[j];
    }

    for (int j = 0; j < m; j++) {
      if (i >> j & 1) continue;

      int already_there_doll_cnt =
          sum[j][already_ordered_doll_cnt + doll_cnt[j]] -
          sum[j][already_ordered_doll_cnt];
      chmin(dp[i + pow(2, j)], dp[i] + doll_cnt[j] - already_there_doll_cnt);
    }
  }

  cout << dp[pow(2, m) - 1] << endl;

  return 0;
}
