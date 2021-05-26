#include <bits/stdc++.h>
using namespace std;

int main() {
  auto is_prime = [](int x) {
    if (x == 1) return false;

    int i = 2;
    while (i * i <= x) {
      if (x % i == 0) return false;
      i++;
    }
    return true;
  };

  int x;
  cin >> x;

  while (true) {
    if (is_prime(x)) {
      cout << x << endl;
      return 0;
    }
    x++;
  }

  return 0;
}
