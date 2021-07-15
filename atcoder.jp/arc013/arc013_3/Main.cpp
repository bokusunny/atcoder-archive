#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

vector<vector<long long>> XYZ, mx, mn;
const long long INF = 1LL << 62;

int main() {
  int N;
  cin >> N;
  XYZ.resize(N, vector<long long>(3));
  mx.resize(N, vector<long long>(3)), mn.assign(N, vector<long long>(3, INF));
  for (int i = 0; i < N; i++) {
    cin >> XYZ[i][0] >> XYZ[i][1] >> XYZ[i][2];
    int M;
    cin >> M;
    for (int j = 0; j < M; j++) {
      long long x, y, z;
      cin >> x >> y >> z;
      chmax(mx[i][0], x), chmin(mn[i][0], x);
      chmax(mx[i][1], y), chmin(mn[i][1], y);
      chmax(mx[i][2], z), chmin(mn[i][2], z);
    }
  }

  long long grundy_xor = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      grundy_xor ^= mn[i][j];
      grundy_xor ^= XYZ[i][j] - mx[i][j] - 1;
    }
  }

  if (grundy_xor == 0) {
    cout << "LOSE" << endl;
  } else {
    cout << "WIN" << endl;
  }

  return 0;
}
