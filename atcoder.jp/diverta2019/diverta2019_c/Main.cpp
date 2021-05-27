#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int last_a_cnt = 0;
  int head_b_cnt = 0;
  int head_b_last_a_cnt = 0;
  int ans = 0;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    if (s[0] == 'B' && s[(int)s.size() - 1] == 'A') {
      head_b_last_a_cnt++;
    } else {
      if (s[0] == 'B') head_b_cnt++;
      if (s[(int)s.size() - 1] == 'A') last_a_cnt++;
    }

    for (int j = 1; j < (int)s.size(); j++) {
      if (s[j - 1] == 'A' && s[j] == 'B') ans++;
    }
  }

  if (head_b_last_a_cnt > 0) {
    ans += head_b_last_a_cnt - 1;
    if (head_b_cnt > 0 && last_a_cnt > 0) {
      cout << ans + min(head_b_cnt - 1, last_a_cnt - 1) + 2 << endl;
    } else if (head_b_cnt > 0 || last_a_cnt > 0) {
      cout << ans + 1 << endl;
    } else {
      cout << ans << endl;
    }
  } else {
    cout << ans + min(head_b_cnt, last_a_cnt) << endl;
  }

  return 0;
}
