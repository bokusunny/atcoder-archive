#include <bits/stdc++.h>
using namespace std;

int N;
// memo[c1][c2][c3] := 寿司k(1<=k<=3)個の皿がck個の時、全て無くすための期待値
long double memo[301][301][301];
bool checked[301][301][301];
int Cnt[4];

long double rec(int c1, int c2, int c3) {
  if (c1 == 0 && c2 == 0 && c3 == 0) return 0;
  if (checked[c1][c2][c3]) return memo[c1][c2][c3];
  long double t = c1 + c2 + c3;

  long double ret = N / t;
  if (c1 > 0) ret += (long double)(c1) / t * rec(c1 - 1, c2, c3);
  if (c2 > 0) ret += (long double)(c2) / t * rec(c1 + 1, c2 - 1, c3);
  if (c3 > 0) ret += (long double)(c3) / t * rec(c1, c2 + 1, c3 - 1);

  checked[c1][c2][c3] = true;
  return memo[c1][c2][c3] = ret;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    Cnt[a]++;
  }

  cout << setprecision(10) << rec(Cnt[1], Cnt[2], Cnt[3]) << endl;

  return 0;
}
