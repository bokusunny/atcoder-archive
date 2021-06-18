#include <bits/stdc++.h>
using namespace std;

long long n;
int cnt = 0;

auto dfs(string s) {
  if (s.size() != 0 && stoll(s) > n) return;

  if (count(s.begin(), s.end(), '3') >= 1 && count(s.begin(), s.end(), '5') >= 1 &&
      count(s.begin(), s.end(), '7') >= 1) {
    cnt++;
  }

  dfs(s + '3');
  dfs(s + '5');
  dfs(s + '7');
}

int main() {
  cin >> n;
  dfs("");

  cout << cnt << endl;

  return 0;
}
