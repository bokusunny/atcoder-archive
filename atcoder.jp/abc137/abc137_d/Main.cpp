#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  map<int, vector<long long>> J;
  for (int i = 0; i < N; i++) {
    int A;
    long long B;
    cin >> A >> B;
    J[A].push_back(B);
  }

  priority_queue<long long, vector<long long>, less<long long>> pq;

  long long ans = 0;
  for (int i = 1; i <= M; i++) {
    for (auto B : J[i]) pq.push(B);
    if (pq.empty()) continue;
    ans += pq.top();
    pq.pop();
  }

  cout << ans << endl;

  return 0;
}
