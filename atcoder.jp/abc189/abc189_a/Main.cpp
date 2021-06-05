#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  if (s.at(0) == s.at(1) && s.at(1) == s.at(2)) {
    cout << "Won" << endl;
  } else {
    cout << "Lost" << endl;
  }

  return 0;
}
