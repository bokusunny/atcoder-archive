#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  string S;
  cin >> N >> S;
  int cnt = count(S.begin(), S.end(), '1');

  if (cnt == 1) {
    for (int i = 0; i < N; i++) {
      if (S[i] == '0') {
        if (i == N - 1 || S[N - 1] == '1') {
          cout << 2 << endl;
        } else {
          cout << 1 << endl;
        }
      } else {
        cout << 0 << endl;
      }
    }
    return;
  }

  vector<int> Amari(N);
  int cur0 = 0, cur1 = 0;
  for (int i = 0; i < N; i++) {
    cur0 *= 2;
    cur1 *= 2;
    cur0 += S[i] - '0';
    cur1 += S[i] - '0';
    cur0 %= cnt + 1;
    cur1 %= cnt - 1;
  }
  for (int i = 0; i < N; i++) {
    if (S[i] == '1') {
      Amari[i] = cur1;
    } else {
      Amari[i] = cur0;
    }
  }
  int two0 = 1;
  int two1 = 1;
  for (int i = 0; i < N; i++) {
    if (S[N - i - 1] == '1') {
      Amari[N - i - 1] = ((Amari[N - i - 1] - two1) % (cnt - 1) + (cnt - 1)) % (cnt - 1);
    } else {
      Amari[N - i - 1] = (Amari[N - i - 1] + two0) % (cnt + 1);
    }
    two0 *= 2;
    two0 %= cnt + 1;
    two1 *= 2;
    two1 %= cnt - 1;
  }

  vector<int> Memo(N, -1);
  function<int(int x)> dfs = [&](int x) {
    if (Memo[x] != -1) return Memo[x];
    if (x == 1) return Memo[x] = 1;
    if (x == 0) return Memo[x] = 0;

    return dfs(x % __builtin_popcount(x)) + 1;
  };

  for (int i = 0; i < N; i++) {
    cout << dfs(Amari[i]) + 1 << endl;
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
