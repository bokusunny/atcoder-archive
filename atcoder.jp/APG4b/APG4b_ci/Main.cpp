#include <bits/stdc++.h>
// #include<iostream>
// #include<string>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int a,b,c;
  cin >>a>>b>>c;

  cout << max(max(a,b),c)-min(min(a,b),c) << endl;
}
