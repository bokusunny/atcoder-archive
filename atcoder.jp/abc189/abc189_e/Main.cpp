#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<vector<long long>> XY(N, vector<long long>(3, 1));
  for (int i = 0; i < N; i++) cin >> XY[i][0] >> XY[i][1];

  int M;
  cin >> M;
  vector<vector<vector<long long>>> Mat(M + 1, vector<vector<long long>>(3, vector<long long>(3)));
  Mat[0] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  for (int i = 0; i < M; i++) {
    vector<vector<long long>> target;
    int op;
    cin >> op;

    if (op == 1) {
      target = {{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}};
    } else if (op == 2) {
      target = {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};
    } else if (op == 3) {
      long long p;
      cin >> p;
      target = {{-1, 0, 2LL * p}, {0, 1, 0}, {0, 0, 1}};
    } else if (op == 4) {
      long long p;
      cin >> p;
      target = {{1, 0, 0}, {0, -1, 2LL * p}, {0, 0, 1}};
    }

    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          Mat[i + 1][j][k] += target[j][l] * Mat[i][l][k];
        }
      }
    }
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int A, B;
    cin >> A >> B;
    B--;
    long long x = 0, y = 0;
    for (int i = 0; i < 3; i++) {
      x += Mat[A][0][i] * XY[B][i];
      y += Mat[A][1][i] * XY[B][i];
    }
    cout << x << " " << y << endl;
  }
}

int main() {
  solve();

  return 0;
}
