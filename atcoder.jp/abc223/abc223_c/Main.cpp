#include <bits/stdc++.h>
using namespace std;

const long double EPS = 1e-11;

void solve() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
  double all = 0;
  for (int i = 0; i < N; i++) {
    all += (double)A[i] / B[i];
  }

  auto is_ok = [&](double x) {
    double t = 0;
    int i = 0;
    for (; i < N; i++) {
      if (x - EPS > A[i]) {
        x -= A[i];
        t += (double)A[i] / B[i];
      } else {
        break;
      }
    }
    if (i < N) t += x / B[i];

    return t <= all / 2;
  };

  double ok = 0, ng = 1 << 30;
  for (int i = 0; i < 1000; i++) {
    double mid = (ok + ng) / 2;
    if (is_ok(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << setprecision(15) << ok << endl;
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
