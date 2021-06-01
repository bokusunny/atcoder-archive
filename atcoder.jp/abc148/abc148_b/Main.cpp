#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 0; i < n; i++) {
    cout << s1.at(i);
    cout << s2.at(i);
  }

  cout << endl;

  return 0;
}
