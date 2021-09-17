#include <bits/stdc++.h>
using namespace std;

void solve() {
  vector B(2, vector<int>(3));
  vector C(3, vector<int>(2));
  int sum = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> B[i][j];
      sum += B[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> C[i][j];
      sum += C[i][j];
    }
  }

  map<vector<vector<int>>, int> Memo;
  const int INF = 1 << 30;
  function<int(vector<vector<int>> &, int)> dfs = [&](vector<vector<int>> &Cur, int t) {
    if (Memo.count(Cur)) return Memo[Cur];
    if (t == 9) {
      int res = 0;
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
          if (Cur[i][j] == Cur[i + 1][j]) {
            res += B[i][j];
          } else {
            res -= B[i][j];
          }
        }
      }
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
          if (Cur[i][j] == Cur[i][j + 1]) {
            res += C[i][j];
          } else {
            res -= C[i][j];
          }
        }
      }
      return Memo[Cur] = res;
    } else {
      if (t & 1) {
        int res = INF;
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            if (Cur[i][j] != -1) continue;
            Cur[i][j] = (t & 1);
            res = min(res, dfs(Cur, t + 1));
            Cur[i][j] = -1;
          }
        }

        return Memo[Cur] = res;
      } else {
        int res = -INF;
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            if (Cur[i][j] != -1) continue;
            Cur[i][j] = (t & 1);
            res = max(res, dfs(Cur, t + 1));
            Cur[i][j] = -1;
          }
        }

        return Memo[Cur] = res;
      }
    }
  };

  vector Grid(3, vector<int>(3, -1));
  auto val = dfs(Grid, 0);
  auto anst = (sum + val) / 2;
  auto ansa = sum - anst;

  cout << anst << endl << ansa << endl;
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
