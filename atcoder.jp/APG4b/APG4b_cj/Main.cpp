#include <bits/stdc++.h>
// #include<iostream>
// #include<string>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n,total=0,tmp=0;
  cin >> n;
  vector<int> vec(n);

  rep(i, n) {
    cin >> vec[i];
    total += vec[i];
  }

  int ave = total/n;
  rep(i, n) {
    cout << abs(vec[i]-ave) << endl;
  }
}
