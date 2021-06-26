#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<tuple<int, int, int, int, int, int>> zahyo(N);

  vector<long long> X, Y, Z;
  for (int i = 0; i < N; i++) {
    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    zahyo[i] = {x1, y1, z1, x2, y2, z2};
    X.push_back(x1), X.push_back(x2);
    Y.push_back(y1), Y.push_back(y2);
    Z.push_back(z1), Z.push_back(z2);
  }

  sort(X.begin(), X.end());
  X.erase(unique(X.begin(), X.end()), X.end());
  sort(Y.begin(), Y.end());
  Y.erase(unique(Y.begin(), Y.end()), Y.end());
  sort(Z.begin(), Z.end());
  Z.erase(unique(Z.begin(), Z.end()), Z.end());

  long long ans = 0;
  // 各ブロックの番号
  for (int x = 0; x < (int)X.size() - 1; x++) {
    for (int y = 0; y < (int)Y.size() - 1; y++) {
      for (int z = 0; z < (int)Z.size() - 1; z++) {
        int cnt = 0;

        for (int i = 0; i < N; i++) {
          auto [x1, y1, z1, x2, y2, z2] = zahyo[i];
          if (x1 <= X[x] && X[x + 1] <= x2 && y1 <= Y[y] && Y[y + 1] <= y2 && z1 <= Z[z] && Z[z + 1] <= z2) cnt++;
        }
        if (cnt >= K) ans += (X[x + 1] - X[x]) * (Y[y + 1] - Y[y]) * (Z[z + 1] - Z[z]);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
