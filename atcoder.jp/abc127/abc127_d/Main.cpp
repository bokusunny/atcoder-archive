#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  int n, m;
  cin >> n >> m;
  map<long long, long long> dic;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    dic.count(a) ? dic[a]++ : dic[a] = 1;
  }
  for (int i = 0; i < m; i++) {
    int b, c;
    cin >> b >> c;

    dic.count(c) ? dic[c] += b : dic[c] = b;
  }

  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 less<pair<long long, long long>>>
      h;
  for (auto [key, value] : dic) {
    h.push(make_pair(key, value));
  }

  long long ans = 0;
  while (n > 0) {
    pair<long long, long long> p = h.top();
    h.pop();
    if (n >= p.second) {
      ans += (p.first * p.second);
      n -= p.second;
    } else {
      ans += (p.first * n);
      n = 0;
    }
  }

  cout << ans << endl;

  return 0;
}
