#include <bits/stdc++.h>
// #include<iostream>
// #include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  int tmp = 1;

  rep(i, S.size()) {
    if (i%2 == 1) {
      if (S.at(i) == '+') tmp++;
      else tmp--;
    }
  }

  cout << tmp << endl;
}
