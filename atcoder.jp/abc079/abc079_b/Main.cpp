#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pb push_back

using ll = long long;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using pii = pair<int, int>;

template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}
// --------------------------------------------------------
vll memo(87, -1);

ll lucas(int i) {
  if (memo[i] != -1) return memo[i];

  return memo[i] = lucas(i-1)+lucas(i-2);
}

int main() {
  int n;
  cin >> n;
  memo[0] = 2LL;
  memo[1] = 1LL;

  cout << lucas(n) << endl;
}
