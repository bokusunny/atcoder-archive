#include <bits/stdc++.h>
// #include<iostream>
// #include<string>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  vector<int> vec(5);
  string ans = "NO";

  rep(i,5) {
    cin >> vec.at(i);
  }

  rep(i,4) {
    if (vec.at(i) == vec.at(i+1)) {ans = "YES";break;}
  }

  cout << ans << endl;
}

