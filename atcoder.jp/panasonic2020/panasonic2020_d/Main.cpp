#include <bits/stdc++.h>
using namespace std;

int n;

void dfs(string s, char max_char) {
  if ((int)s.size() == n) {
    cout << s << endl;
  } else {
    for (char c = 'a'; c <= max_char; c++) {
      dfs(s + c, c == max_char ? max_char + 1 : max_char);
    }
  }
}

int main() {
  cin >> n;

  dfs("", 'a');

  return 0;
}
