#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a_product = 1;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a_product *= a;
  }
  int m;
  cin >> m;
  int b_product = 1;
  for (int i = 0; i < m; i++) {
    int b;
    cin >> b;
    b_product *= b;
  }

  if (a_product == b_product) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
