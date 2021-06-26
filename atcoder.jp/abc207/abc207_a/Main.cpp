#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int tmp = min(a, b);
  tmp = min(tmp, c);

  cout << a + b + c - tmp << endl;

  return 0;
}
