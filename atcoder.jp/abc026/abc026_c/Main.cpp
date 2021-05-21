#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  int n;
  cin >> n;
  vector<vector<int>> buka_list(n);
  for (int i = 1; i < n; i++) {
    int boss;
    cin >> boss;
    boss--;
    buka_list[boss].push_back(i);
  }
  vector<int> salary_memo(n, -1);

  function<int(int)> calc_salary = [&](int x) {
    if (salary_memo[x] != -1) return salary_memo[x];
    if (buka_list[x].size() == 0) {
      salary_memo[x] = 1;
      return 1;
    }

    int buka_salary_max = -1;
    int buka_salary_min = pow(10, 9);
    for (int buka : buka_list[x]) {
      int salary = calc_salary(buka);
      if (salary > buka_salary_max) buka_salary_max = salary;
      if (salary < buka_salary_min) buka_salary_min = salary;
    }

    int salary = buka_salary_max + buka_salary_min + 1;
    salary_memo[x] = salary;
    return salary;
  };

  cout << calc_salary(0) << endl;

  return 0;
}
