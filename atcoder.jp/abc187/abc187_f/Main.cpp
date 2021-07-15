#include <bits/stdc++.h>
using namespace std;

int N, M;
const int INF = 100;
vector<int> memo;
int G[18];

bool is_complete_graph(int bit) {
  for (int i = 0; i < N; i++) {
    if ((bit >> i & 1) == 0) continue;
    for (int j = i + 1; j < N; j++) {
      if ((bit >> j & 1) == 0) continue;

      if ((G[i] >> j & 1) == 0) return false;
    }
  }

  return true;
}

int rec(int bit) {
  if (memo[bit] != INF) return memo[bit];

  int ret = INF;
  for (int mask = (bit - 1) & bit; mask != 0; mask = (mask - 1) & bit) {
    int tmp = rec(mask) + rec(bit ^ mask);
    if (tmp < ret) ret = tmp;
  }

  return memo[bit] = ret;
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    G[A] |= 1 << B;
    G[B] |= 1 << A;
  }
  memo.assign(1 << N, INF);

  for (int i = 1; i < 1 << N; i++)
    if (is_complete_graph(i)) memo[i] = 1;

  cout << rec((1 << N) - 1) << endl;

  return 0;
}
