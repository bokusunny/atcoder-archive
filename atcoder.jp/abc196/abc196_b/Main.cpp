#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int i = s.find('.');

  if (i == string::npos) {
    cout << s;
  } else {
    for (int j = 0; j < i; j++) cout << s[j];
  }
  cout << endl;

  return 0;
}
