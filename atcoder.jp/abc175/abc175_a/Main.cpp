#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int ans = count(s.begin(), s.end(), 'R');
  if (ans == 2 && s.at(0) == 'R' && s.at(2) == 'R') ans--;
  cout << ans << endl;

  return 0;
}
