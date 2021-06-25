#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int right_cnt = 0, left_cnt = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == '(')
      right_cnt++;
    else
      right_cnt = max(0, right_cnt - 1);
  }
  for (int i = N - 1; i >= 0; i--) {
    if (S[i] == ')')
      left_cnt++;
    else
      left_cnt = max(0, left_cnt - 1);
  }

  string ans;
  for (int i = 0; i < left_cnt; i++) ans += '(';
  ans += S;
  for (int i = 0; i < right_cnt; i++) ans += ')';
  cout << ans << endl;

  return 0;
}
