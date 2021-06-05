#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> A(n);
  long long a_sum = 0;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    A.at(i) = a;
    a_sum += a;
  }
  vector<long long> B(n);
  long long b_sum = 0;
  for (int i = 0; i < n; i++) {
    long long b;
    cin >> b;
    B.at(i) = b;
    b_sum += b;
  }

  long long oper_cnt = b_sum - a_sum;

  long long a_minimum_oper = 0, b_minimum_oper = 0;
  for (int i = 0; i < n; i++) {
    long long a = A.at(i), b = B.at(i);
    if (a > b) {
      b_minimum_oper += a - b;
    } else if (b > a) {
      if ((b - a) % 2 == 0) {
        a_minimum_oper += (b - a) / 2;
      } else {
        a_minimum_oper += (b - a) / 2 + 1;
        b_minimum_oper++;
      }
    }
  }

  if (oper_cnt < max(a_minimum_oper, b_minimum_oper)) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

  return 0;
}
