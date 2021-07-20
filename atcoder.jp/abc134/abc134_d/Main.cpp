#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A, memo;

int rec(int k) {
  if (memo[k] != -1) return memo[k];
  int sum = 0;
  for (int i = 2 * k; i <= N; i += k) sum += rec(i);
  return memo[k] = sum % 2 != A[k];
}

int main() {
  cin >> N;
  A.resize(N + 1), memo.assign(N + 1, -1);
  for (int i = 1; i <= N; i++) cin >> A[i];

  rec(1);

  int M = 0;
  vector<int> B;
  for (int i = 1; i <= N; i++)
    if (memo[i]) M++, B.push_back(i);
  cout << M << endl;
  if (M != 0) {
    for (auto b : B) cout << b << " ";
    cout << endl;
  }

  return 0;
}
