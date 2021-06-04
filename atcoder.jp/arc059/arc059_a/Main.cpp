#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> A(n);
  for (auto &a : A) cin >> a;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += A.at(i);
  }
  int ave = sum / n;

  long long ans1 = 0;
  for (int i = 0; i < n; i++) {
    ans1 += (ave - A.at(i)) * (ave - A.at(i));
  }
  ave++;
  long long ans2 = 0;
  for (int i = 0; i < n; i++) {
    ans2 += (ave - A.at(i)) * (ave - A.at(i));
  }

  cout << min(ans1, ans2) << endl;

  return 0;
}
