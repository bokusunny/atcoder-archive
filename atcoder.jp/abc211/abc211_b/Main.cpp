#include <bits/stdc++.h>
using namespace std;

int main() {
  set<string> st;
  for (int i = 0; i < 4; i++) {
    string S;
    cin >> S;
    st.insert(S);
  }

  if ((int)st.size() == 4) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
