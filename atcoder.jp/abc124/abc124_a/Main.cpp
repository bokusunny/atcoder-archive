#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  if (a == b) {
    cout << a + b << endl;
  } else {
    int c = max(a, b);
    cout << c + c - 1 << endl;
  }

  return 0;
}
