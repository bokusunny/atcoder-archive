#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  map<int, int> M;
  M[0]++;
  int ans = 0, prev = 0, ten = 1;
  for (int i = (int)S.size() - 1; i >= 0; i--) {
    int cur = (prev + ten * (S[i] - '0')) % 2019;
    ans += M[cur];
    M[cur]++;
    prev = cur;
    ten = ten * 10 % 2019;
  }

  cout << ans << endl;

  return 0;
}
