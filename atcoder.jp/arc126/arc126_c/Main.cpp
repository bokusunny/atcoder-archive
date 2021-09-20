#include <bits/stdc++.h>
using namespace std;

#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)

// vector
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (T &x : vec) is >> x;
  return is;
}
// pair
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
  os << "(" << pair_var.first << ", " << pair_var.second << ")";
  return os;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "{";
  for (int i = 0; i < vec.size(); i++) {
    os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
  }
  os << "}";
  return os;
}
// map
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
  os << "{";
  repi(itr, map_var) {
    os << *itr;
    itr++;
    if (itr != map_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}
// set
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
  os << "{";
  repi(itr, set_var) {
    os << *itr;
    itr++;
    if (itr != set_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}

#define DUMPOUT cerr

void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&...tail) {
  DUMPOUT << head;
  if (sizeof...(Tail) > 0) {
    DUMPOUT << ", ";
  }
  dump_func(std::move(tail)...);
}
#ifdef DEBUG_
#define DEB
#define dump(...) DUMPOUT << "  " << string(#__VA_ARGS__) << endl << "    ", dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif

void solve() {
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  long long tot = accumulate(A.begin(), A.end(), 0LL);
  auto mx = *max_element(A.begin(), A.end());

  if (tot + K < mx * N) {
    int MX = mx + 10;
    vector<long long> RuiA(MX + 1);
    vector<int> RuiCnt(MX + 1);
    for (auto &a : A) {
      RuiA[a] += a;
      RuiCnt[a]++;
    }
    for (int i = 0; i < MX; i++) {
      RuiA[i + 1] += RuiA[i];
      RuiCnt[i + 1] += RuiCnt[i];
    }
    for (int g = MX; g >= 2; g--) {
      long long cost = 0;
      int L = 0;
      int R = g;
      while (L < MX) {
        int cnt = RuiCnt[min(R, MX)] - RuiCnt[L];
        long long tota = RuiA[min(R, MX)] - RuiA[L];
        cost += 1LL * R * cnt - tota;
        // dump(L, R, cnt, tota, cost);
        L += g;
        R += g;
      }
      if (cost <= K) {
        cout << g << endl;
        return;
      }
    }
    cout << 1 << endl;
  } else {
    long long ans = mx;
    K -= mx * N - tot;
    cout << ans + K / N << endl;
  }
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
