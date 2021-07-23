#include <bits/stdc++.h>
using namespace std;

long long digsum(string n) {
  long long res = 0;
  for (int i = 0; i < (int)n.size(); i++) {
    res += n[i] - '0';
  }
  return res;
}

int main() {
  string A, B;
  cin >> A >> B;

  cout << max(digsum(A), digsum(B)) << endl;

  return 0;
}
