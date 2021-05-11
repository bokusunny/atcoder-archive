#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
// --------------------------------------------------------
int count_doc_num(vector<vector<int>> &child_info, int par) {
  vector<int> child_list = child_info.at(par);
  if (child_list.size() == 0) return 1;
  int total = 0;
  for (int child: child_list) {
    total += count_doc_num(child_info, child);
  }
  return total+1;
}
int main() {
  int n;
  cin >> n;
  vector<vector<int>> child_info(n);
  rep2(i, 1, n) {
    int p;
    cin >> p;
    child_info.at(p).push_back(i);
  }

  rep(i, n) {
    cout << count_doc_num(child_info, i) << endl;
  }
}
