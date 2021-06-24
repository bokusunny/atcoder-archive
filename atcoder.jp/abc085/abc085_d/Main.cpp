#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, H;
  cin >> N >> H;

  long long max_a = 0;
  vector<long long> b_of_max_a;
  vector<pair<long long, long long>> V(N);
  for (int i = 0; i < N; i++) {
    long long A, B;
    cin >> A >> B;
    if (A > max_a) {
      max_a = A, b_of_max_a = {B};
    } else if (A == max_a) {
      b_of_max_a.push_back(B);
    }
    V[i] = {B, A};
  }
  sort(V.begin(), V.end(), greater<pair<long long, long long>>());
  sort(b_of_max_a.begin(), b_of_max_a.end());

  int ans = 0;
  int i = 0;
  while (H > 0 && i < N && V[i].first >= max_a) {
    auto [B, A] = V[i];
    i++;
    if (A == max_a && (int)b_of_max_a.size() == 1) continue;

    H -= B;
    if (A == max_a) b_of_max_a.pop_back();
    ans++;
  }

  if (H <= 0) {
    cout << ans << endl;
    return 0;
  }

  assert((int)b_of_max_a.size() == 1);
  H -= b_of_max_a[0];
  ans++;
  if (H <= 0) {
    cout << ans << endl;
    return 0;
  }

  cout << ans + (H + (max_a - 1)) / max_a << endl;

  return 0;
}
