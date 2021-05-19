#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  priority_queue<double, vector<double>, less<double>> q;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    q.push((double)a);
  }

  for (int i = 0; i < m; i++) {
    double max = q.top();
    q.pop();
    q.push(max / 2);
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    double a = q.top();
    q.pop();
    ans += (long long)a;
  }

  cout << ans << endl;

  return 0;
}
