#include <bits/stdc++.h>
using namespace std;

int N, K;
string S;

int main() {
  cin >> N >> K >> S;

  int cnt = 1;
  for (int i = 1; i < N; i++) {
    if (S[i] != S[i - 1]) cnt++;
  }

  for (int i = 0; i < K; i++) {
    if (cnt >= 3)
      cnt -= 2;
    else if (cnt == 2)
      cnt--;
  }

  cout << N - cnt << endl;

  return 0;
}
