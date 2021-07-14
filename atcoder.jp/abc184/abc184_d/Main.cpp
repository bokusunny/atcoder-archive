#include <bits/stdc++.h>
using namespace std;

int A, B, C;
long double memo[101][101][101];
bool checked[101][101][101];

long double rec(int a, int b, int c) {
  if (a == 100 || b == 100 || c == 100) return 0;
  if (checked[a][b][c]) return memo[a][b][c];

  int sum = a + b + c;
  long double ret = 1.0;
  ret += (long double)(a) / (long double)sum * rec(a + 1, b, c);
  ret += (long double)(b) / (long double)sum * rec(a, b + 1, c);
  ret += (long double)(c) / (long double)sum * rec(a, b, c + 1);

  checked[a][b][c] = true;
  return memo[a][b][c] = ret;
}

int main() {
  cin >> A >> B >> C;

  cout << setprecision(9) << rec(A, B, C) << endl;

  return 0;
}
