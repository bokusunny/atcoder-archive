#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    v.emplace_back(make_pair(x, y));
  }

  auto is_icchokusen_vec = [](vector<pair<int, int>> pv) {
    if ((int)pv.size() < 3) {
      cout << "pv size is too small!" << endl;
      return false;
    }

    int x1 = pv.at(0).first - pv.at(1).first;
    int y1 = pv.at(0).second - pv.at(1).second;
    for (int i = 2; i < (int)pv.size(); i++) {
      auto p = pv.at(i);
      int xi = pv.at(0).first - pv.at(i).first;
      int yi = pv.at(0).second - pv.at(i).second;

      if (x1 * yi != xi * y1) return false;
    }

    return true;
  };

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (is_icchokusen_vec({v.at(i), v.at(j), v.at(k)})) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
