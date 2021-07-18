#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  priority_queue<int, vector<int>, greater<int>> A, B, C;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push(a);
  }
  for (int i = 0; i < N; i++) {
    int b;
    cin >> b;
    B.push(b);
  }
  for (int i = 0; i < N; i++) {
    int c;
    cin >> c;
    C.push(c);
  }

  int ans = 0;
  while (!A.empty()) {
    int a = A.top();
    A.pop();
    while (!B.empty() && B.top() <= a) B.pop();
    if (B.empty()) break;
    int b = B.top();
    B.pop();
    while (!C.empty() && C.top() <= b) C.pop();
    if (C.empty()) break;
    C.pop();
    ans++;
  }

  cout << ans << endl;

  return 0;
}
