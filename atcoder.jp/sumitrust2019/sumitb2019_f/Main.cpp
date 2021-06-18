#include <bits/stdc++.h>
using namespace std;

int main() {
  long long t1, t2;
  cin >> t1 >> t2;
  long long a1, a2;
  cin >> a1 >> a2;
  long long b1, b2;
  cin >> b1 >> b2;

  long long a_cycle_dis = a1 * t1 + a2 * t2, b_cycle_dis = b1 * t1 + b2 * t2;

  if (a_cycle_dis == b_cycle_dis) {
    cout << "infinity" << endl;
    return 0;
  }

  long long cycle_dis_diff = a_cycle_dis - b_cycle_dis;
  long long t1_cycle_dis = a1 * t1 - b1 * t1;

  if ((cycle_dis_diff > 0 && t1_cycle_dis > 0) || (cycle_dis_diff < 0 && t1_cycle_dis < 0)) {
    cout << 0 << endl;
    return 0;
  }

  if (abs(t1_cycle_dis) % abs(cycle_dis_diff) == 0) {
    cout << (abs(t1_cycle_dis) / abs(cycle_dis_diff)) * 2 << endl;
  } else {
    cout << (abs(t1_cycle_dis) / abs(cycle_dis_diff)) * 2 + 1 << endl;
  }

  return 0;
}
