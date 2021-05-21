#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<pair<int, int>> A;
  for (int i = 1; i < n + 1; i++) {
    int cnt;
    cin >> cnt;
    A.push_back(make_pair(i, cnt));
  }

  for (int i = 0; i < h; i++) {
    vector<int> row;
    int left = w;
    while (left > 0) {
      pair<int, int> p = A[(int)A.size() - 1];
      int val, cnt;
      tie(val, cnt) = p;
      A.pop_back();

      if (cnt <= left) {
        for (int k = 0; k < cnt; k++) row.push_back(val);
        left -= cnt;
      } else {
        for (int k = 0; k < left; k++) row.push_back(val);
        A.push_back(make_pair(val, cnt - left));
        left = 0;
      }
    }

    if (i % 2) reverse(row.begin(), row.end());
    for (int k = 0; k < (int)row.size(); k++) {
      cout << row[k];
      if (k != (int)row.size() - 1) cout << " ";
    }
    cout << endl;
  }

  return 0;
}
