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
  int N;
  cin >> N;

  if (N % digsum(to_string(N)) == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
