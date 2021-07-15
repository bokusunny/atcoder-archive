#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> grundy;

int rec(int w, int b) {
  if (grundy[w][b] != -1) return grundy[w][b];
  if (w == 0 && b <= 1) return grundy[w][b] = 0;

  vector<bool> mex(1500);
  if (w >= 1) mex[rec(w - 1, b + w)] = true;
  for (int k = 1; k <= b / 2; k++) mex[rec(w, b - k)] = true;
  for (int i = 0; i < 1500; i++)
    if (!mex[i]) return grundy[w][b] = i;
}

int main() {
  int N;
  cin >> N;
  vector<int> W(N), B(N);
  for (int i = 0; i < N; i++) cin >> W[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  grundy.assign(55, vector<long long>(1500, -1));

  // 山が一つの場合のGrundy数を前計算
  for (int w = 0; w <= 50; w++) {
    for (int b = 0; b <= 50; b++) {
      rec(w, b);
    }
  }

  int grundy_xor = 0;
  for (int i = 0; i < N; i++) {
    grundy_xor ^= grundy[W[i]][B[i]];
  }

  if (grundy_xor == 0) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }

  return 0;
}
