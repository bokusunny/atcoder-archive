#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  string s;
  cin >> s;

  int passed = 0, passed_abroad = 0;
  for (auto c : s) {
    if (c == 'c') {
      cout << "No" << endl;
    } else if (c == 'a') {
      if (passed < a + b) {
        cout << "Yes" << endl;
        passed++;
      } else {
        cout << "No" << endl;
      }
    } else {
      if (passed < a + b && passed_abroad < b) {
        cout << "Yes" << endl;
        passed++, passed_abroad++;
      } else {
        cout << "No" << endl;
      }
    }
  }

  return 0;
}
