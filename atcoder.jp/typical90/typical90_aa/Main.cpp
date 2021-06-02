#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  set<string> S;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    if (S.count(s) == 0) {
      cout << i << endl;
      S.insert(s);
    }
  }

  return 0;
}
