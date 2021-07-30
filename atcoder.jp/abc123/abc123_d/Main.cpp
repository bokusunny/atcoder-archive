#include <bits/stdc++.h>
using namespace std;

int X, Y, Z, K;
vector<long long> A, B, C;
vector<long long> AB, ABC;

void solve() {
  sort(A.begin(), A.end(), greater<long long>());
  sort(B.begin(), B.end(), greater<long long>());
  sort(C.begin(), C.end(), greater<long long>());

  using T = tuple<long long, int, int, int>;
  priority_queue<T, vector<T>, less<T>> pq;
  set<T> seen;
  vector<long long> ans;
  pq.emplace(A[0] + B[0] + C[0], 0, 0, 0);
  seen.emplace(A[0] + B[0] + C[0], 0, 0, 0);

  while (K > 0) {
    auto [val, i, j, k] = pq.top();
    pq.pop();
    ans.push_back(val);

    if (i + 1 < X && !seen.count({A[i + 1] + B[j] + C[k], i + 1, j, k})) {
      pq.emplace(A[i + 1] + B[j] + C[k], i + 1, j, k);
      seen.emplace(A[i + 1] + B[j] + C[k], i + 1, j, k);
    }
    if (j + 1 < Y && !seen.count({A[i] + B[j + 1] + C[k], i, j + 1, k})) {
      pq.emplace(A[i] + B[j + 1] + C[k], i, j + 1, k);
      seen.emplace(A[i] + B[j + 1] + C[k], i, j + 1, k);
    }
    if (k + 1 < Z && !seen.count({A[i] + B[j] + C[k + 1], i, j, k + 1})) {
      pq.emplace(A[i] + B[j] + C[k + 1], i, j, k + 1);
      seen.emplace(A[i] + B[j] + C[k + 1], i, j, k + 1);
    }
    K--;
  }

  for (auto a : ans) cout << a << endl;
}

void cinout() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> X >> Y >> Z >> K;
  A.resize(X), B.resize(Y), C.resize(Z);
  for (int i = 0; i < X; i++) cin >> A[i];
  for (int i = 0; i < Y; i++) cin >> B[i];
  for (int i = 0; i < Z; i++) cin >> C[i];
}

int main() {
  cinout();
  solve();

  return 0;
}
