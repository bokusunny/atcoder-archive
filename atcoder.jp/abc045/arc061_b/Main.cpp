#include <bits/stdc++.h>
using namespace std;

void solve() {
  int H, W, N;
  cin >> H >> W >> N;

  set<pair<int, int>> seen;
  vector<long long> Cnt(10);
  Cnt[0] = 1LL * (H - 2) * (W - 2);
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    for (int py = 0; py < 3; py++) {
      for (int px = 0; px < 3; px++) {
        bool ok = true;
        int cnt = 0;
        for (int cy = 0; cy < 3; cy++) {
          for (int cx = 0; cx < 3; cx++) {
            int y = a - py + cy;
            int x = b - px + cx;
            if (y < 0 || H <= y || x < 0 || W <= x) {
              ok = false;
              break;
            }
            if (seen.count(make_pair(y, x))) cnt++;
          }
        }
        if (!ok) continue;
        Cnt[cnt]--;
        Cnt[cnt + 1]++;
      }
    }
    seen.insert(make_pair(a, b));
  }

  for (int i = 0; i < 10; i++) {
    cout << Cnt[i] << endl;
  }
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
