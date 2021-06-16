#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l;
  cin >> n >> l;

  string ans = "";
  vector<string> v;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    ans += v.at(i);
  }

  cout << ans << endl;

  return 0;
}
