#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> sa(n + 1, 0);
  vector<int> st(n + 1, 0);
  vector<int> sc(n + 1, 0);
  vector<int> sg(n + 1, 0);

  for (int i = 0; i < n; i++) {
    sa.at(i + 1) += sa.at(i);
    st.at(i + 1) += st.at(i);
    sg.at(i + 1) += sg.at(i);
    sc.at(i + 1) += sc.at(i);
    if (s.at(i) == 'A') sa.at(i + 1)++;
    if (s.at(i) == 'T') st.at(i + 1)++;
    if (s.at(i) == 'C') sc.at(i + 1)++;
    if (s.at(i) == 'G') sg.at(i + 1)++;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (sa.at(j + 1) - sa.at(i) - (st.at(j + 1) - st.at(i)) != 0) continue;
      if (sc.at(j + 1) - sc.at(i) - (sg.at(j + 1) - sg.at(i)) != 0) continue;
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
