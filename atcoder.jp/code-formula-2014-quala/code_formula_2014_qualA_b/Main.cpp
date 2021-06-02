#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  set<int> P;
  for (int i = 0; i < a; i++) {
    int p;
    cin >> p;

    P.insert(p);
  }
  set<int> Q;
  for (int i = 0; i < b; i++) {
    int q;
    cin >> q;

    Q.insert(q);
  }

  auto out = [&](int i) {
    if (P.count(i)) {
      cout << ". ";
    } else if (Q.count(i)) {
      cout << "o ";
    } else {
      cout << "x ";
    }
  };

  for (int i = 7; i < 10; i++) out(i);
  out(0);
  cout << endl;
  for (int i = 4; i < 7; i++) out(i);
  cout << endl;
  for (int i = 2; i < 4; i++) out(i);
  cout << endl;
  out(1);
  cout << endl;

  return 0;
}
