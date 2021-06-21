#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int i = a - b + c;
  if (i > 0)
    cout << "Takahashi" << endl;
  else
    cout << "Aoki" << endl;

  return 0;
}
