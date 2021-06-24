#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  cin >> k;

  queue<string> q;
  for (int i = 1; i < 10; i++) q.push(to_string(i));

  while (!q.empty()) {
    string s = q.front();
    q.pop();
    k--;
    if (k == 0) {
      cout << s << endl;
      return 0;
    }
    auto c = *s.rbegin() - '0';
    if (c != 0) q.push(s + to_string(c - 1));
    q.push(s + to_string(c));
    if (c != 9) q.push(s + to_string(c + 1));
  }

  return 0;
}
