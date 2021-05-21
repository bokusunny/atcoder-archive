#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;

  set<char> unique_char_set;
  for (char c : s1) unique_char_set.insert(c);
  for (char c : s2) unique_char_set.insert(c);
  for (char c : s3) unique_char_set.insert(c);

  if (unique_char_set.size() > 10) {
    cout << "UNSOLVABLE" << endl;
    return 0;
  }

  vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  do {
    map<char, int> dic;
    auto itr = unique_char_set.begin();
    int i = 0;
    while (itr != unique_char_set.end()) {
      dic[(*itr)] = v[i];
      itr++;
      i++;
    }

    if (dic[s1[0]] == 0 || dic[s2[0]] == 0 || dic[s3[0]] == 0) continue;
    string n1_s = "", n2_s = "", n3_s = "";
    for (char c : s1) n1_s += (dic[c] + '0');
    for (char c : s2) n2_s += (dic[c] + '0');
    for (char c : s3) n3_s += (dic[c] + '0');

    if (stol(n1_s) + stol(n2_s) == stol(n3_s)) {
      cout << n1_s << endl;
      cout << n2_s << endl;
      cout << n3_s << endl;
      return 0;
    }
  } while (next_permutation(v.begin(), v.end()));

  cout << "UNSOLVABLE" << endl;

  return 0;
}
