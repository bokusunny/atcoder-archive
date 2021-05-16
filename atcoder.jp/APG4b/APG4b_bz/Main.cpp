#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using ll = long long;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using pii = pair<int, int>;
using mii = map<int, int>;

template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}
// --------------------------------------------------------
int main() {
  int n;
  cin >> n;
  mii dic;
  rep(_,n) {
    int a;
    cin >> a;
    if (dic.count(a)) {
      dic.at(a)++;
    } else {
      dic[a] = 1;
    }
  }

  pii ans(0,0);
  for (auto p: dic) {
    if (ans.second<p.second) ans = p;
  }

  cout<<ans.first<<" "<<ans.second<<endl;
}
