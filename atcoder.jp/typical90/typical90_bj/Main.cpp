#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> I(N);
  queue<int> q;
  vector<bool> queued(N);
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    if (i == A || i == B) {
      q.push(i);
      queued[i] = true;
    } else {
      I[A].push_back(i);
      I[B].push_back(i);
    }
  }

  vector<int> ans;
  while (!q.empty()) {
    auto i = q.front();
    q.pop();
    ans.push_back(i + 1);
    for (auto item : I[i]) {
      if (queued[item]) continue;
      q.push(item);
      queued[item] = true;
    }
  }

  if ((int)ans.size() != N) {
    cout << -1 << endl;
  } else {
    for (int i = N - 1; i >= 0; i--) {
      cout << ans[i] << endl;
    }
  }

  return 0;
}
