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

string S;
vector<vector<long long>> memo;

long long rec(int l, int r) {
  if (r - l <= 1) return 0;
  if (r - l == 2) return S.substr(l, 3) == "iwi";
  if (memo[l][r] != -1) return memo[l][r];

  for (int i = l; i < r; i++) chmax(memo[l][r], rec(l, i) + rec(i + 1, r));
  if (S[l] == 'i' && S[r] == 'i' && (r - l) % 3 == 2) {
    for (int i = l + 1; i < r; i += 3) {
      if (S[i] == 'w' && rec(l + 1, i - 1) == (i - l - 1) / 3 && rec(i + 1, r - 1) == (r - i - 1) / 3) {
        memo[l][r] = (r - l + 1) / 3;
      }
    }
  }

  return memo[l][r];
}

int main() {
  cin >> S;
  int N = (int)S.size();
  memo.assign(N, vector<long long>(N, -1));

  cout << rec(0, N - 1) << endl;

  return 0;
}
