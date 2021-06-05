#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  map<int, int> M;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    if (M.count(a)) {
      M.at(a)++;
    } else {
      M[a] = 1;
    }
  }

  vector<int> v;
  int color_num = 0;
  for (auto [key, val] : M) {
    color_num++;
    v.push_back(val);
  }
  sort(v.begin(), v.end(), greater<int>());

  int ans = 0;
  while (color_num > k) {
    ans += v.at((int)v.size() - 1);
    v.pop_back();
    color_num--;
  }

  cout << ans << endl;

  return 0;
}
