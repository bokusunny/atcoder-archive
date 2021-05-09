#include <bits/stdc++.h>
// #include<iostream>
// #include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n,a,b;
  string op;

  cin >> n >> a;

  rep2(i,1,n+1) {
    cin >> op >> b;
    if (op == "+") a+=b;
    else if (op == "-") a-=b;
    else if (op == "*") a*=b;
    else if (op == "/") {
      if (b == 0) {
        cout << "error" << endl;
        break;
      }
      else a/=b;
    }
    cout << i << ":" << a << endl;
  }
}
