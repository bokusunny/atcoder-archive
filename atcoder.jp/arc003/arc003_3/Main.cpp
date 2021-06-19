#include <bits/stdc++.h>
using namespace std;

bool grid_bfs(vector<vector<char>> &grid, pair<int, int> s, long double x) {
  int h = (int)grid.size(), w = (int)grid.at(0).size();
  const int INF = 1000000001;
  vector<vector<int>> dist(h, vector<int>(w, INF));
  queue<pair<int, int>> q;
  q.push(s);
  dist.at(s.first).at(s.second) = 0;
  vector<pair<int, int>> moving = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  while (!q.empty()) {
    auto [cur_y, cur_x] = q.front();
    q.pop();

    for (auto [mv_y, mv_x] : moving) {
      int target_y = cur_y + mv_y, target_x = cur_x + mv_x;

      if (target_y >= h || target_y < 0 || target_x >= w || target_x < 0) {
        continue;
      }

      if (dist.at(target_y).at(target_x) != INF || grid.at(target_y).at(target_x) == '#') continue;

      if (grid.at(target_y).at(target_x) == 'g') return true;

      int t_nxt = dist.at(cur_y).at(cur_x) + 1;
      if ((double)(grid.at(target_y).at(target_x) - '0') * pow(0.99, t_nxt) < x) continue;

      dist.at(target_y).at(target_x) = t_nxt;
      q.push(make_pair(target_y, target_x));
    }
  }

  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  pair<int, int> start;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      char c = s.at(j);
      if (c == 's') start = {i, j};
      grid.at(i).at(j) = c;
    }
  }

  long double ok = -1.0, ng = 10.0;

  while (abs(ok - ng) > 1e-10) {
    long double mid = (ok + ng) / 2;
    if (grid_bfs(grid, start, mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  if (ok == -1.0) {
    cout << -1 << endl;
  } else {
    cout << setprecision(10) << ok << endl;
  }

  return 0;
}
