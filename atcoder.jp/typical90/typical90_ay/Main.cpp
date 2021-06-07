#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  long long p;
  cin >> p;
  if (n == 1) {
    long long a;
    cin >> a;
    cout << (a <= p) << endl;
    return 0;
  }

  vector<long long> vec_0;
  vector<long long> vec_1;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;

    if (i % 2 == 1) {
      vec_1.push_back(a);
    } else {
      vec_0.push_back(a);
    }
  }

  // v0_sum.at(i): vec_0からi個選んだ時の合計値の集合(重複OK)
  vector<vector<long long>> v0_sums((int)vec_0.size() + 1);
  vector<vector<long long>> v1_sums((int)vec_1.size() + 1);

  for (int i = 0; i < (1 << (int)vec_0.size()); i++) {
    long long tmp = 0;
    int flag_cnt = 0;
    for (int j = 0; j < (int)vec_0.size(); j++) {
      if (i >> j & 1) {
        tmp += vec_0.at(j);
        flag_cnt++;
      }
    }
    v0_sums.at(flag_cnt).push_back(tmp);
  }
  for (int i = 0; i < (1 << (int)vec_1.size()); i++) {
    long long tmp = 0;
    int flag_cnt = 0;
    for (int j = 0; j < (int)vec_1.size(); j++) {
      if (i >> j & 1) {
        tmp += vec_1.at(j);
        flag_cnt++;
      }
    }
    v1_sums.at(flag_cnt).push_back(tmp);
  }

  long long ans = 0;
  for (int vec_0_select_size = 0; vec_0_select_size <= (int)vec_0.size(); vec_0_select_size++) {
    int vec_1_select_size = k - vec_0_select_size;
    if (vec_1_select_size > (int)vec_1.size() || vec_1_select_size < 0) continue;

    auto v0_sum = v0_sums.at(vec_0_select_size);
    auto v1_sum = v1_sums.at(vec_1_select_size);
    sort(v1_sum.begin(), v1_sum.end());

    for (auto s : v0_sum) {
      long long max_v1_sum = p - s;
      ans += upper_bound(v1_sum.begin(), v1_sum.end(), max_v1_sum) - v1_sum.begin();
    }
  }

  cout << ans << endl;

  return 0;
}
