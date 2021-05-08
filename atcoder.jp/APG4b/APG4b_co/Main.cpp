#include <bits/stdc++.h>
using namespace std;

int main() {
  int pattern, price, n;
  string text;
  cin >> pattern;

  if (pattern == 1) {
    cin >> price >> n;
  }
  else {
    cin >> text >> price >> n;
    cout << text+"!" << endl;
  }

  cout << price*n << endl;
}
