#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  string A = "", B = "abc", C = "cab";
  string a = "bcabca", b = "abcabc", c = "cabcab";
  for (int i = 0; i < 100; i++) {
    if (A + "b" == S) {
      cout << 3 * i << endl;
      return 0;
    }
    if (B == S) {
      cout << 3 * i + 1 << endl;
      return 0;
    }
    if (C + "ca" == S) {
      cout << 3 * i + 2 << endl;
      return 0;
    }
    A += a, B += b, C += c;
  }

  cout << -1 << endl;

  return 0;
}
