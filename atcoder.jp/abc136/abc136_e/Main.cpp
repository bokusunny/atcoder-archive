#include <bits/stdc++.h>
using namespace std;

vector<int> divisors(int N) {
  vector<int> res;
  for (int i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      res.push_back(i);
      if (N / i != i) res.push_back(N / i);
    }
  }
  sort(res.begin(), res.end(), greater<int>());
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;

  int sum = 0;
  vector<int> A(n);
  for (auto &a : A) {
    cin >> a;
    sum += a;
  }

  auto divs = divisors(sum);

  auto check_min_cost = [&](int gcd) {
    int cost = 0;
    vector<int> R;
    for (auto a : A) {
      if (a % gcd != 0) {
        R.push_back(a % gcd);
      }
    }
    sort(R.begin(), R.end());

    vector<int> s1((int)R.size() + 1);
    vector<int> s2((int)R.size() + 1);
    s1[0] = 0;
    s2[0] = 0;

    for (int i = 0; i < (int)R.size(); i++) {
      s1[i + 1] = s1[i] + R[i];
      s2[i + 1] = s2[i] + (gcd - R[i]);
    }

    for (int i = 0; i < (int)R.size(); i++) {
      if (s1[i] - s1[0] == s2[(int)R.size()] - s2[i]) {
        cost = s1[i] - s1[0];
        break;
      }
    }

    return cost;
  };

  for (auto d : divs) {
    if (check_min_cost(d) <= k) {
      cout << d << endl;
      return 0;
    }
  }

  return 0;
}
