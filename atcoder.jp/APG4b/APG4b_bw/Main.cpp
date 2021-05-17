#include <bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}
// --------------------------------------------------------
int calc_int(map<char, int> &int_dic) {
  auto convert_to_int = [&](char s) {return int_dic.count(s) ? int_dic.at(s) : s-'0';};
  char num_or_var;
  cin>>num_or_var;
  int i = convert_to_int(num_or_var);

  while (true) {
    char semi_or_op;
    cin>>semi_or_op;
    if (semi_or_op==';') break;

    cin>>num_or_var;
    int tmp = convert_to_int(num_or_var);
    semi_or_op == '+' ? i+=tmp : i-=tmp;
  }
  return i;
}

vector<int> calc_vec(map<char, int> &int_dic, map<char, vector<int>> &vec_dic) {
  auto convert_to_int = [&](char s) {return int_dic.count(s) ? int_dic.at(s) : s-'0';};
  auto convert_to_vec = [&](char kigou_or_var) {
    if (kigou_or_var == '[') {
      vector<int> vec;
      while (true) {
        char kigou, num_or_var;
        cin>>num_or_var>>kigou;
        vec.push_back(convert_to_int(num_or_var));
        if (kigou==']') break;
      }
      return vec;
    } else {
      return vec_dic[kigou_or_var];
    }
  };

  char kigou_or_var;
  cin >> kigou_or_var;
  vector<int> first_vec = convert_to_vec(kigou_or_var);
  while (true) {
    char semi_or_op;
    cin>>semi_or_op;
    if (semi_or_op==';') break;

    cin >> kigou_or_var;
    vector<int> vec = convert_to_vec(kigou_or_var);
    rep(i, vec.size()) {
      semi_or_op == '+' ? first_vec.at(i)+=vec.at(i) : first_vec.at(i)-=vec.at(i);
    }
  }

  return first_vec;
}

int main() {
  int n;
  cin>>n;
  map<char, int> int_dic;
  map<char, vector<int>> vec_dic;
  rep(_, n) {
    string com, _equal;
    cin>>com;
    if (com == "int") {
      char var_name;
      cin>>var_name>>_equal;
      int val = calc_int(int_dic);
      int_dic[var_name] = val;
    } else if (com == "print_int") {
      int val = calc_int(int_dic);
      cout << val << endl;
    } else if (com == "vec") {
      char var_name, _equal;
      cin >> var_name>>_equal;
      vector<int> vec = calc_vec(int_dic, vec_dic);
      vec_dic[var_name] = vec;
    } else if (com == "print_vec") {
      vector<int> vec = calc_vec(int_dic, vec_dic);
      cout << "[ ";
      for (auto i: vec) cout << i << " ";
      cout << "]" << endl;
    }
  }
}

