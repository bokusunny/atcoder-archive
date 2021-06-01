#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> s1(n + 1, 0);
  vector<int> s2(n + 1, 0);

  for (int i = 0; i < n; i++) {
    int c, p;
    cin >> c >> p;

    if (c == 1) {
      s1.at(i + 1) = s1.at(i) + p;
      s2.at(i + 1) = s2.at(i);
    } else {
      s1.at(i + 1) = s1.at(i);
      s2.at(i + 1) = s2.at(i) + p;
    }
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;

    cout << s1.at(r + 1) - s1.at(l) << " " << s2.at(r + 1) - s2.at(l) << endl;
  }

  return 0;
}
