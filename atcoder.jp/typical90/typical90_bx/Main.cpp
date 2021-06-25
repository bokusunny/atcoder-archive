#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(2 * N);
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;
    A[i] = A[N + i] = a;
    sum += a;
  }

  if (sum % 10 != 0) {
    cout << "No" << endl;
    return 0;
  }

  long long target = sum / 10;

  int l = 0;
  long long tmp = 0;
  for (int i = 0; i < 2 * N; i++) {
    tmp += A.at(i);
    if (tmp > target) {
      tmp -= A[l];
      l++;
    }
    if (tmp == target) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;

  return 0;
}
