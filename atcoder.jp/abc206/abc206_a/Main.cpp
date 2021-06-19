#include <bits/stdc++.h>
using namespace std;

int main() {
  double n;
  cin >> n;

  if ((int)(1.08 * n) < 206) {
    cout << "Yay!" << endl;
  } else if ((int)(1.08 * n) == 206) {
    cout << "so-so" << endl;
  } else {
    cout << ":(" << endl;
  }

  return 0;
}
