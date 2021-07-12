#include <bits/stdc++.h>
using namespace std;

int N, Q;
map<int, vector<int>> M;
map<int, bitset<90>> seen;
int A[90];

void print(bitset<90> bit) {
  cout << bit.count() << endl;
  for (int i = 0; i < N; i++)
    if (bit[i]) cout << i + 1 << " ";
  cout << endl;
}

// i: 下から何桁目を見ているか
void dfs(bitset<90> bit, int i) {
  if (i == N) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
      if (bit[i]) sum += A[i];
    }
    if (sum == 0) return;
    if (seen.count(sum)) {
      print(bit);
      print(seen[sum]);
      exit(0);
    } else {
      seen[sum] = bit;
    }
    return;
  }

  dfs(bit, i + 1);
  bool is_ok = true;
  for (auto j : M[i]) {
    if (bit[j]) {
      is_ok = false;
      break;
    }
  }
  if (is_ok) {
    bit.set(i);
    dfs(bit, i + 1);
  }
}

int main() {
  cin >> N >> Q;
  for (int i = 0; i < N; i++) cin >> A[i];

  for (int i = 0; i < Q; i++) {
    int X, Y;
    cin >> X >> Y;
    X--, Y--;

    M[X].push_back(Y);
    M[Y].push_back(X);
  }

  dfs(0, 0);

  return 0;
}
