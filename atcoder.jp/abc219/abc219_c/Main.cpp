#include <bits/stdc++.h>
using namespace std;

void solve() {
  string X;
  cin >> X;
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) cin >> S[i];

  auto comp = [&](string a, string b) {
    for (int i = 0; i < min((int)a.size(), (int)b.size()); i++) {
      if (a[i] == b[i]) continue;
      return find(X.begin(), X.end(), a[i]) < find(X.begin(), X.end(), b[i]);
    }
    return (int)a.size() < (int)b.size();
  };
  sort(S.begin(), S.end(), comp);

  for (auto s : S) cout << s << endl;
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
