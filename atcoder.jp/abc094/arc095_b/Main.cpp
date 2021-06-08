#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> A(n);
  for (auto &a : A) cin >> a;
  sort(A.begin(), A.end());
  auto ai = A.at(n - 1);
  A.pop_back();

  const int INF = 1000000001;
  int aj;
  if (ai % 2 == 0) {
    auto best = ai / 2;
    int min_diff_to_best = INF;
    for (auto a : A) {
      auto diff_to_best = abs(a - best);
      if (diff_to_best < min_diff_to_best) {
        aj = a;
        min_diff_to_best = diff_to_best;
      }
    }
  } else {
    auto best_1 = ai / 2;
    auto best_2 = ai / 2 + 1;
    int min_diff_to_best = INF;
    for (auto a : A) {
      auto diff_to_best1 = abs(a - best_1);
      auto diff_to_best2 = abs(a - best_2);
      if (diff_to_best1 < min_diff_to_best) {
        aj = a;
        min_diff_to_best = diff_to_best1;
      }
      if (diff_to_best2 < min_diff_to_best) {
        aj = a;
        min_diff_to_best = diff_to_best2;
      }
    }
  }

  cout << ai << " " << aj << endl;

  return 0;
}
