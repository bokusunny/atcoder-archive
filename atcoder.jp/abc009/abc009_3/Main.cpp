#include <bits/stdc++.h>
using namespace std;

int calc_cost(string s, multiset<char> t) {
  int same_cnt = 0;
  for (int i = 'a'; i < 'a' + 26; i++) {
    char c = i;
    int s_cnt = count(s.begin(), s.end(), c);
    int t_cnt = t.count(c);
    same_cnt += min(s_cnt, t_cnt);
  }

  return (int)s.size() - same_cnt;
}

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  multiset<char> left_chars;
  for (auto c : s) left_chars.insert(c);

  string ans = "";
  for (int i = 0; i < n; i++) {
    for (auto itr = left_chars.begin(); itr != left_chars.end(); itr++) {
      int cost = s.at(i) == *itr ? 0 : 1;
      multiset<char> tmp = left_chars;
      auto it = tmp.find(*itr);
      tmp.erase(it);
      cost += calc_cost(s.substr(i + 1, n - i - 1), tmp);
      if (k < cost) continue;

      if (s.at(i) != *itr) k -= 1;
      ans += *itr;
      left_chars.erase(itr);
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
