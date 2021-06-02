#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int i = s.find('7');

  s.at(i) = '8';

  cout << s << endl;

  return 0;
}
