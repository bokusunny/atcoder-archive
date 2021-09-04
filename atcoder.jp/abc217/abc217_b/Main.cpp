#include <bits/stdc++.h>
using namespace std;

void solve() {
  string a, b, c;
  cin >> a >> b >> c;
  set<string> st = {"ABC", "ARC", "AGC", "AHC"};
  st.erase(a);
  st.erase(b);
  st.erase(c);

  cout << *st.begin() << endl;
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
