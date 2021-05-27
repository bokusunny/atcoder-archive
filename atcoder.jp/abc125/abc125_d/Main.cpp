#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long ans = 0;

  const long long INF = 1LL << 60;

  long long min_positive_or_zero = INF;
  long long max_negative = -INF;
  int negative_count = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    if (a < 0) {
      negative_count++;
      if (max_negative < a) {
        max_negative = a;
      }
    } else {
      if (min_positive_or_zero > a) {
        min_positive_or_zero = a;
      }
    }

    ans += abs(a);
  }

  if (negative_count % 2 == 0) {
    cout << ans << endl;
  } else {
    int tmp = min(min_positive_or_zero, -max_negative);
    cout << ans - 2 * tmp << endl;
  }

  return 0;
}
