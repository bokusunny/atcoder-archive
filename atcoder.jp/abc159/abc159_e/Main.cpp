#include <bits/stdc++.h>
using namespace std;

int H, W, K;
vector<vector<int>> grid;

void solve() {
  cin >> H >> W >> K;
  grid.resize(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char c;
      cin >> c;

      grid[i][j] = c - '0';
    }
  }

  const int INF = 1 << 30;
  int ans = INF;
  for (int msk = 0; msk < 1 << (H - 1); msk++) {
    int group_size = __builtin_popcount(msk) + 1;
    vector<int> Sum(group_size);
    vector<int> Id(H);  // Id[h] := h行目のグループID
    int id = 0;
    for (int j = 1; j < H; j++) {
      if (msk >> (j - 1) & 1) id++;
      Id[j] = id;
    }

    int cnt = __builtin_popcount(msk);
    for (int j = 0; j < W; j++) {
      vector<int> TmpSum(group_size);

      bool is_ok = true;
      for (int k = 0; k < H; k++) {
        TmpSum[Id[k]] += grid[k][j];
        if (TmpSum[Id[k]] > K) {
          is_ok = false;
          break;
        }
      }
      if (!is_ok) {
        cnt = INF;
        break;
      } else {
        for (int i = 0; i < group_size; i++) {
          Sum[i] += TmpSum[i];
          if (Sum[i] > K) {
            cnt++;
            Sum = TmpSum;
            break;
          }
        }
      }
    }
    ans = min(ans, cnt);
  }

  cout << ans << endl;
}

int main() {
  solve();

  return 0;
}
