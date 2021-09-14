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
  cin >> N;
  vector<int> P(N + 1);
  vector<int> Pos(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> P[i];
    Pos[P[i]] = i;
  }

  long long ans = 0;
  set<int> st;
  st.insert(0);
  st.insert(N + 1);
  for (int i = 1; i <= N; i++) {
    auto itr = st.upper_bound(Pos[i]);
    int upper = *itr;
    int lower = *prev(itr);

    ans += 1LL * i * (upper - Pos[i]) * (Pos[i] - lower);
    st.insert(Pos[i]);
  }

  cout << ans << endl;
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
