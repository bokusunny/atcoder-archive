#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    long long n;
    cin >> n;

    if (n % 2 == 1) {
      cout << "Odd" << endl;
    } else if (n % 4 == 0) {
      cout << "Even" << endl;
    } else {
      cout << "Same" << endl;
    }
  }

  return 0;
}
