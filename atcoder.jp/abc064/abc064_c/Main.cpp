#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------
int main() {
  int n;
  cin >> n;

  set<int> s;
  int master = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    if (a >= 3200) {
      master++;
    } else {
      s.insert(a / 400);
    }
  }

  int non_master = s.size();
  int max = non_master + master;
  int min = non_master ? non_master : 1;
  cout << min << " " << max << endl;
}
