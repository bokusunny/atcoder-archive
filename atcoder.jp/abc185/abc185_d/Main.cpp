#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A = {0};
  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }
  A.push_back(N + 1);
  sort(A.begin(), A.end());

  vector<int> Aida;
  int k = -1;
  for (int i = 1; i < M + 2; i++) {
    auto aida = A[i] - A[i - 1] - 1;
    if (aida <= 0) continue;
    Aida.push_back(aida);
    if (k == -1) {
      k = aida;
    } else {
      k = min(k, aida);
    }
  }

  long long ans = 0;
  for (auto a : Aida) {
    ans += (a + k - 1) / k;
  }

  cout << ans << endl;

  return 0;
}
