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

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

void solve() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int i = 0; i < H; i++) cin >> S[i];

  int cntok = 0;
  for (int i = 0; i < H; i++) {
    cntok += count(S[i].begin(), S[i].end(), '.');
  }
  vector<mint> Pow(cntok + 1);
  Pow[0] = 1;
  for (int i = 0; i < cntok; i++) Pow[i + 1] = Pow[i] * 2;

  vector Left(H, vector<int>(W + 1)), Right(H, vector<int>(W + 1));
  vector Up(W, vector<int>(H + 1)), Down(W, vector<int>(H + 1));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i][j] == '#') continue;
      Left[i][j + 1] = Left[i][j] + 1;
    }
    for (int j = W - 1; j >= 0; j--) {
      if (S[i][j] == '#') continue;
      Right[i][j] = Right[i][j + 1] + 1;
    }
  }
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
      if (S[i][j] == '#') continue;
      Up[j][i + 1] += Up[j][i] + 1;
    }
    for (int i = H - 1; i >= 0; i--) {
      if (S[i][j] == '#') continue;
      Down[j][i] = Down[j][i + 1] + 1;
    }
  }

  mint ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i][j] == '#') continue;
      int cnt = 0;
      cnt += Left[i][j + 1];
      cnt += Up[j][i + 1];
      cnt += Right[i][j + 1];
      cnt += Down[j][i + 1];
      cnt--;
      ans += Pow[cntok] - Pow[cntok - cnt];
    }
  }

  cout << ans.val() << endl;
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
