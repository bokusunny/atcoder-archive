#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------
int main() {
  string s;
  cin >> s;

  for (int i = 2; i < s.size(); i += 2) {
    string left = s.substr(0, s.size() - i);
    string left_half = left.substr(0, left.size() / 2);
    string right_half = left.substr(left.size() / 2);
    if (left_half == right_half) {
      cout << left.size() << endl;
      break;
    }
  }
  return 0;
}
