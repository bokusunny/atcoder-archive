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
int main() {
  int m;
  ll keta_count = 0, keta_sum = 0;
  cin >> m;

  rep(_, m) {
    int d;
    ll c;
    cin >> d >> c;
    keta_count += c;
    keta_sum += d*c;
  }

  cout << keta_count-1+(keta_sum-1)/9 << endl;
}
