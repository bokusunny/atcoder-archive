#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pb push_back

using ll = long long;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using pii = pair<int, int>;

template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}
// --------------------------------------------------------
void calc_score(vvi &grid, const int &k, ll &total, const int &shometsu_count) {
  int h = grid.size();
  int w = grid[0].size();
  bool is_shoumetsu_happened = false;
  rep(i, h) {
    int target_i = grid[i][0];
    int succession = 1;
    rep2(j, 1, w) {
      if (grid.at(i).at(j) == target_i) {
        succession++;
        if (succession >= k && j == w-1 && target_i != -1) {
          rep2(x, j-succession+1, j+1) {
            int h_i = i;
            while(true) {
              if (grid.at(h_i).at(x) == -1) {
                break;
              } else if (h_i == 0) {
                grid.at(h_i).at(x) = -1;
                break;
              } else {
                grid.at(h_i).at(x) = grid.at(h_i-1).at(x);
                h_i--;
              }
            }
          }
          total += pow(2,shometsu_count)*target_i*succession;
          is_shoumetsu_happened = true;
        }
      } else {
        if (succession >= k && target_i != -1) {
          rep2(x, j-succession, j) {
            int h_i = i;
            while(true) {
              if (grid.at(h_i).at(x) == -1) {
                break;
              } else if (h_i == 0) {
                grid.at(h_i).at(x) = -1;
                break;
              } else {
                grid.at(h_i).at(x) = grid.at(h_i-1).at(x);
                h_i--;
              }
            }
          }
          total += pow(2,shometsu_count)*target_i*succession;
          is_shoumetsu_happened = true;
        }
        target_i = grid[i][j];
        succession = 1;
      }
    }
  }
  if (is_shoumetsu_happened) {
    calc_score(grid, k, total, shometsu_count+1);
  }
}

vvi init_grid(vvi grid, const int &init_h, const int &init_w) {
  rep(i, grid.size()) {
    if (i != init_h) continue;
    rep(j, grid.at(0).size()) {
      if (j != init_w) continue;

      while (true) {
        if (i == 0) {
          grid.at(i).at(j) = -1;
          return grid;
        } else {
          grid.at(i).at(j) = grid.at(i-1).at(j);
          i--;
        }
      }
    }
  }
}

int main() {
  int h,w,k;
  cin >> h >> w >> k;

  vvi grid(h, vi(w));
  rep(i,h) {
    string str;
    cin >> str;
    rep(j, w) {
      grid.at(i).at(j) = str.at(j)-'0';
    }
  }

  ll ans = 0;
  rep(i, h) {
    rep(j, w) {
      ll tmp_total = 0;
      vvi initialized_grid = init_grid(grid, i, j);
      calc_score(initialized_grid, k, tmp_total, 0);
      chmax(ans, tmp_total);
    }
  }

  cout << ans << endl;
}
