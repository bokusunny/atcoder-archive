#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<long long> A(3 * N);
  for (int i = 0; i < 3 * N; i++) cin >> A[i];

  vector<long long> Front(2 * N + 1);
  long long cur1 = 0;
  priority_queue<long long, vector<long long>, greater<long long>> pq1;
  for (int i = 0; i < N; i++) {
    cur1 += A[i];
    pq1.push(A[i]);
  }
  Front[N] = cur1;
  for (int i = N + 1; i <= 2 * N; i++) {
    cur1 += A[i - 1];
    pq1.push(A[i - 1]);
    auto removed = pq1.top();
    pq1.pop();
    cur1 -= removed;
    Front[i] = cur1;
  }
  vector<long long> Back(2 * N + 1);
  long long cur2 = 0;
  priority_queue<long long, vector<long long>, less<long long>> pq2;
  for (int i = 2 * N; i < 3 * N; i++) {
    cur2 += A[i];
    pq2.push(A[i]);
  }
  Back[2 * N] = cur2;
  for (int i = 2 * N - 1; i >= N; i--) {
    cur2 += A[i];
    pq2.push(A[i]);
    auto removed = pq2.top();
    pq2.pop();
    cur2 -= removed;
    Back[i] = cur2;
  }

  const long long INF = 1LL << 62;
  auto ans = -INF;
  for (int i = N; i <= 2 * N; i++) {
    ans = max(ans, Front[i] - Back[i]);
  }

  cout << ans << endl;
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
