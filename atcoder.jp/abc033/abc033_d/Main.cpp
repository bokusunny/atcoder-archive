#include <bits/stdc++.h>
using namespace std;

struct Point {
  long double x, y;

  Point operator-(const Point& other) { return Point{x - other.x, y - other.y}; }

  double get_rad() { return atan2(y, x); }
};

const long double EPS = 1e-11;

int main() {
  int N;
  cin >> N;
  vector<Point> P(N);
  for (int i = 0; i < N; i++) cin >> P[i].x >> P[i].y;

  long long chokkaku = 0, donkaku = 0, eikaku = 0;
  // for (int i = 2; i < 3; i++) {
  for (int i = 0; i < N; i++) {
    vector<long double> Rad;

    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      auto vec = P[j] - P[i];
      auto r = vec.get_rad();
      Rad.push_back(r);
    }
    auto R = Rad;
    for (auto r : Rad) {
      R.push_back(r + 2.0 * M_PI);
      R.push_back(r - 2.0 * M_PI);
    }
    sort(R.begin(), R.end());

    for (auto r : Rad) {
      int eikaku_tmp = 0, chokkaku_tmp = 0;
      long double target1 = r - M_PI / 2.0 - EPS, target2 = r + M_PI / 2.0 + EPS;
      auto itr2 = lower_bound(R.begin(), R.end(), target2), itr1 = lower_bound(R.begin(), R.end(), target1);
      eikaku_tmp += itr2 - itr1 - 1;  // 自分を含んでいる
      if (abs(*itr1 - (target1 + EPS)) < EPS) chokkaku_tmp++;
      itr2--;
      if (abs(*itr2 - (target2 - EPS)) < EPS) chokkaku_tmp++;
      chokkaku += chokkaku_tmp, eikaku += (eikaku_tmp - chokkaku_tmp), donkaku += (N - 2 - eikaku_tmp);
    }
  }

  // 全て2回ずつ数えられているはず
  assert(chokkaku % 2 == 0);
  assert(donkaku % 2 == 0);
  assert(eikaku % 2 == 0);
  chokkaku /= 2, donkaku /= 2, eikaku /= 2;

  // 直角三角形、鈍角三角形それぞれ1つごとに鋭角を2個ずつ余分に数えている
  eikaku -= (2 * chokkaku + 2 * donkaku);

  // 残った鋭角3個で鋭角三角形を構成
  assert(eikaku % 3 == 0);
  eikaku /= 3;

  cout << eikaku << " " << chokkaku << " " << donkaku << endl;

  return 0;
}
