#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    pq.emplace(a, i);
  }
  pq.pop();
  cout << pq.top().second << endl;
}

int main() {
  solve();

  return 0;
}
