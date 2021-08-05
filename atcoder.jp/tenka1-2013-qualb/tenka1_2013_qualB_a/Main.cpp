#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<string> S(15);
  for (int i = 0; i < 15; i++) cin >> S[i];
  sort(S.begin(), S.end());

  cout << S[6] << endl;

  return 0;
}
