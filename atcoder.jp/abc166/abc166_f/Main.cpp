#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<long long> V(3);
  cin >> V[0] >> V[1] >> V[2];
  vector<pair<int, int>> S(N);
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    S[i].first = s[0] - 'A';
    S[i].second = s[1] - 'A';
  }

  vector<char> ans;
  for (int i = 0; i < N; i++) {
    auto [x, y] = S[i];
    if (V[x] == 0 && V[y] == 0) {
      cout << "No" << endl;
      return;
    }
    if (V[x] > V[y]) {
      V[x]--;
      V[y]++;
      ans.push_back('A' + y);
    } else if (V[x] < V[y]) {
      V[x]++;
      V[y]--;
      ans.push_back('A' + x);
    } else {
      if (i < N - 1) {
        if (S[i] == S[i + 1]) {
          V[x]++;
          V[y]--;
          ans.push_back('A' + x);
        } else {
          int nxt_unseen = 3 - S[i + 1].first - S[i + 1].second;
          V[x + y - nxt_unseen]++;
          V[nxt_unseen]--;
          ans.push_back('A' + x + y - nxt_unseen);
        }
      } else {
        V[x]++;
        V[y]--;
        ans.push_back('A' + x);
      }
    }
  }

  cout << "Yes" << endl;
  for (auto &a : ans) cout << a << endl;
}

void setcin() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  setcin();
  solve();

  return 0;
}
