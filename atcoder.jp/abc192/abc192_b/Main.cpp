#include <bits/stdc++.h>
using namespace std;

bool is_komoji(char c) { return 'Z' - c < 0; }

int main() {
  string S;
  cin >> S;

  for (int i = 0; i < (int)S.size(); i++) {
    if (i % 2 == 0) {
      if (!is_komoji(S[i])) {
        cout << "No" << endl;
        return 0;
      }
    } else {
      if (is_komoji(S[i])) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;

  return 0;
}
