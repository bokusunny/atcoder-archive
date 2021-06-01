#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> va(46, 0);
  vector<long long> vb(46, 0);
  vector<long long> vc(46, 0);

  for (int i = 0; i < n; i++) {
    int n;
    cin >> n;
    n %= 46;
    va.at(n)++;
  }
  for (int i = 0; i < n; i++) {
    int n;
    cin >> n;
    n %= 46;
    vb.at(n)++;
  }
  for (int i = 0; i < n; i++) {
    int n;
    cin >> n;
    n %= 46;
    vc.at(n)++;
  }

  long long ans = 0;
  for (int i = 0; i < 46; i++) {
    for (int j = 0; j < 46; j++) {
      for (int k = 0; k < 46; k++) {
        if ((i + j + k) % 46 != 0) continue;
        ans += va.at(i) * vb.at(j) * vc.at(k);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
