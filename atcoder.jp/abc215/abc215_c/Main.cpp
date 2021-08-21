#include <bits/stdc++.h>
using namespace std;

void solve() {
  string S;
  cin >> S;
  int K;
  cin >> K;

  vector<int> v;
  for (int i = 0; i < (int)S.size(); i++) v.push_back(i);

  set<string> st;
  do {
    string tmp = "";
    for (auto i : v) tmp += S[i];
    st.insert(tmp);
  } while (next_permutation(v.begin(), v.end()));

  vector<string> V(st.begin(), st.end());
  cout << V[K - 1] << endl;
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
