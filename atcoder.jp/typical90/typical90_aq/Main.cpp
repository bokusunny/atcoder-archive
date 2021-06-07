#include <bits/stdc++.h>
using namespace std;

auto grid_dijkstra(vector<vector<int>> &grid, pair<int, int> s, pair<int, int> g) {
  int grid_h = (int)grid.size();
  int grid_w = (int)grid.at(0).size();
  const long long INF = 1LL << 60;
  vector<vector<long long>> dist(grid_h, vector<long long>(grid_w, INF));
  using T = tuple<long long, int, int, int>;
  priority_queue<T, vector<T>, greater<T>> h;
  h.push({0LL, s.first, s.second, -1});
  dist.at(s.first).at(s.second) = 0;

  while (!h.empty()) {
    long long dis_s_to_cur;
    int cur_y, cur_x, prev_dir;
    tie(dis_s_to_cur, cur_y, cur_x, prev_dir) = h.top();
    h.pop();

    if (dis_s_to_cur > dist.at(cur_y).at(cur_x)) continue;

    vector<tuple<int, int, int>> grid_moving = {{0, 0, 1}, {1, 0, -1}, {2, 1, 0}, {3, -1, 0}};
    for (auto [cur_dir, mv_y, mv_x] : grid_moving) {
      int target_y = cur_y + mv_y, target_x = cur_x + mv_x;
      if (target_y < 0 || target_y == grid_h || target_x < 0 || target_x == grid_w) {
        continue;
      }

      if (grid.at(target_y).at(target_x) == 0) continue;

      long long dis_s_to_nxt = dis_s_to_cur;
      if (prev_dir != -1 && prev_dir != cur_dir) {
        dis_s_to_nxt++;
      }

      if (dis_s_to_nxt > dist.at(target_y).at(target_x)) continue;

      dist.at(target_y).at(target_x) = dis_s_to_nxt;
      h.push({dis_s_to_nxt, target_y, target_x, cur_dir});
    }
  }

  cout << dist.at(g.first).at(g.second) << endl;
}

int main() {
  int h, w;
  cin >> h >> w;
  int rs, cs, rg, cg;
  cin >> rs >> cs >> rg >> cg;
  rs--, cs--, rg--, cg--;

  vector<vector<int>> grid(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c;
      cin >> c;

      grid.at(i).at(j) = c == '.' ? 1 : 0;
    }
  }

  grid_dijkstra(grid, make_pair(rs, cs), make_pair(rg, cg));

  return 0;
}
