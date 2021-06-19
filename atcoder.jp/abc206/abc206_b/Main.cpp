#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;

  long long sum = 0;
  long long i = 1;
  while (true) {
    sum += i;
    if (sum >= n) {
      cout << i << endl;
      return 0;
    }
    i++;
  }

  return 0;
}
