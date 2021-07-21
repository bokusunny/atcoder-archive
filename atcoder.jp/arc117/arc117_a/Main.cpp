#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;

  vector<long long> E;
  for (int i = 1; i <= A; i++) E.push_back(i);
  for (int i = 1; i <= B; i++) E.push_back(-i);
  if (A > B) {
    E[A + B - 1] -= (A + B + 1) * (A - B) / 2;
  } else {
    E[A - 1] += (A + B + 1) * (B - A) / 2;
  }

  for (auto e : E) cout << e << " ";
  cout << endl;

  return 0;
}
