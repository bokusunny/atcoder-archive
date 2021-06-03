#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> field(1001, vector<int>(1001, 0));

  for (int i = 0; i < n; i++) {
    int lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;

    field.at(ly).at(lx)++;
    field.at(ly).at(rx)--;
    field.at(ry).at(lx)--;
    field.at(ry).at(rx)++;
  }

  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      field.at(i).at(j + 1) += field.at(i).at(j);
    }
  }
  for (int j = 0; j < 1000; j++) {
    for (int i = 0; i < 1000; i++) {
      field.at(i + 1).at(j) += field.at(i).at(j);
    }
  }

  vector<int> cnt(n + 1, 0);
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      cnt.at(field.at(i).at(j))++;
    }
  }

  for (int i = 1; i <= n; i++) cout << cnt.at(i) << endl;

  return 0;
}
