#include <bits/stdc++.h>
using namespace std;

int N, W;
vector<long long> v, w;
const long long INF = 1LL << 62;

void solve1() {
  vector<long long> v0, w0, v1, w1;
  for (int i = 0; i < N; i++) {
    if (i & 1) {
      v0.push_back(v[i]);
      w0.push_back(w[i]);
    } else {
      v1.push_back(v[i]);
      w1.push_back(w[i]);
    }
  }
  int sz0 = (int)v0.size(), sz1 = (int)v1.size();
  vector<pair<long long, long long>> I0, I1;
  for (int msk = 0; msk < 1 << sz0; msk++) {
    long long vs = 0, ws = 0;
    for (int j = 0; j < sz0; j++) {
      if (msk >> j & 1) {
        vs += v0[j];
        ws += w0[j];
      }
    }
    if (ws > W) continue;
    I0.emplace_back(ws, vs);
  }
  for (int msk = 0; msk < 1 << sz1; msk++) {
    long long vs = 0, ws = 0;
    for (int j = 0; j < sz1; j++) {
      if (msk >> j & 1) {
        vs += v1[j];
        ws += w1[j];
      }
    }
    if (ws > W) continue;
    I1.emplace_back(ws, vs);
  }
  sort(I1.begin(), I1.end());
  for (int i = 1; i < (int)I1.size(); i++) {
    I1[i].second = max(I1[i].second, I1[i - 1].second);
  }

  long long ans = 0;
  for (auto [w, v] : I0) {
    int ok = -1, ng = I1.size();
    while (abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;
      if (w + I1[mid].first <= W) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    ans = max(ans, v + I1[ok].second);
  }

  cout << ans << endl;
}

void solve2() {
  const int MX = min(W + 1, 3 * 100000);
  vector dp(N + 1, vector<long long>(MX));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < MX; j++) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j + w[i] < MX) dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
    }
  }

  cout << *max_element(dp[N].begin(), dp[N].end()) << endl;
}

void solve3() {
  const int MX = 3 * 100000;
  vector dp(N + 1, vector<long long>(MX, INF));  // i番目まで見て価値の総和がjになるときの最小重量
  dp[0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < MX; j++) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      if (j + v[i] < MX) dp[i + 1][j + v[i]] = min(dp[i + 1][j + v[i]], dp[i][j] + w[i]);
    }
  }

  int ans = 0;
  for (int i = 0; i < MX; i++) {
    if (dp[N][i] <= W) ans = i;
  }

  cout << ans << endl;
}

void solve() {
  cin >> N >> W;
  v.resize(N), w.resize(N);
  long long max_v = 0, max_w = 0;
  for (int i = 0; i < N; i++) {
    cin >> v[i] >> w[i];
    max_v = max(max_v, v[i]);
    max_w = max(max_w, w[i]);
  }

  if (N <= 30) {
    solve1();
  } else if (max_w <= 1000) {
    solve2();
  } else {
    solve3();
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
