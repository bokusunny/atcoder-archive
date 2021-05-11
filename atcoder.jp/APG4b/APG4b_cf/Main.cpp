#include <bits/stdc++.h>
// #include<iostream>
// #include<string>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n,s;
  cin >> n >> s;
  vector<int> al(n), pl(n);

  rep(i,n) {cin >> al.at(i);}
  rep(i,n) {cin >> pl.at(i);}

  int ans = 0;
  for (int a: al) {
    for (int p: pl) {
      if (a+p == s) {ans++;}
    }
  }

  cout << ans << endl;
}

