#include <bits/stdc++.h>
using namespace std;

int main() {
  string T;
  cin >> T;

  for (auto &c : T) {
    if (c == '?') c = 'D';
  }

  cout << T << endl;

  return 0;
}
