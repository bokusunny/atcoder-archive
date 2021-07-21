#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  int H, W, M;
  cin >> H >> W >> M;

  vector<int> h(M), w(M);
  vector<int> hcnt(H), wcnt(W);
  set<pair<int, int>> st;
  for (int i = 0; i < M; i++) {
    cin >> h[i] >> w[i];
    h[i]--, w[i]--;
    hcnt[h[i]]++, wcnt[w[i]]++;
    st.insert({h[i], w[i]});
  }

  int max_cnt_h = 0, max_cnt_w = 0;
  for (auto cnt : hcnt) chmax(max_cnt_h, cnt);
  for (auto cnt : wcnt) chmax(max_cnt_w, cnt);
  vector<int> max_h_i, max_w_i;
  for (int i = 0; i < H; i++)
    if (hcnt[i] == max_cnt_h) max_h_i.push_back(i);
  for (int i = 0; i < W; i++)
    if (wcnt[i] == max_cnt_w) max_w_i.push_back(i);

  int ans = max_cnt_h + max_cnt_w - 1;
  set<pair<int, int>> S;
  for (auto i : max_h_i) {
    for (auto j : max_w_i) {
      if (!st.count({i, j})) {
        ans++;
        cout << ans << endl;
        return 0;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
