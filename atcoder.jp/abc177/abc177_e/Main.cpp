#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> prime_factorize(int N) {
  vector<pair<int, int>> res;
  for (int i = 2; i * i <= N; i++) {
    if (N % i != 0) continue;
    int ex = 0;
    while (N % i == 0) {
      ex++;
      N /= i;
    }
    res.push_back({i, ex});
  }

  if (N != 1) res.push_back({N, 1});
  return res;
}

int gcd_vector(vector<int> v) {
  int res = v[0];
  for (int i = 1; i < (int)v.size(); i++) {
    res = gcd(res, v[i]);
    if (res == 1) return 1;
  }

  return res;
}

int main() {
  int n;
  cin >> n;

  vector<int> A(n);
  for (auto &a : A) cin >> a;

  set<int> seen_prime;
  bool is_pairwise_coprime = true;

  for (int i = 0; i < n; i++) {
    auto pf = prime_factorize(A.at(i));
    if (i == 0) {
      for (auto [prime, ex] : pf) seen_prime.insert(prime);
    } else {
      bool is_common_prime_exist = false;
      for (auto [prime, ex] : pf) {
        if (seen_prime.count(prime)) {
          is_pairwise_coprime = false;
        } else {
          seen_prime.insert(prime);
        }
      }
    }
  }

  if (is_pairwise_coprime) {
    cout << "pairwise coprime" << endl;
    return 0;
  }

  if (gcd_vector(A) == 1) {
    cout << "setwise coprime" << endl;
  } else {
    cout << "not coprime" << endl;
  }

  return 0;
}
