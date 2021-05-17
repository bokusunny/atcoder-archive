#include <bits/stdc++.h>
using namespace std;

// 以下に、24時間表記の時計構造体 Clock を定義する
struct Clock {
// Clock構造体のメンバ変数を書く
  int hour=0, minute=0, second=0;

// メンバ関数 set の定義を書く
//   関数名: set
//   引数: int h, int m, int s (それぞれ時、分、秒を表す)
//   返り値: なし
//   関数の説明:
//     時・分・秒を表す3つの引数を受け取り、
//     それぞれ、メンバ変数 hour, minute, second に代入する
void set(int h, int m, int s) {
  hour = h;
  minute = m;
  second = s;
}

// メンバ関数 to_str の定義を書く
//   関数名: to_str
//   引数: なし
//   返り値: string型
//   関数の仕様:
//     メンバ変数が表す時刻の文字列を返す
//     時刻の文字列は次のフォーマット
//     "HH:MM:SS"
//     HH、MM、SSはそれぞれ時間、分、秒を2桁で表した文字列
  string to_time_format(int x) {
    if (0<=x&&x<=9) return "0"+to_string(x);
    else return to_string(x);
  }

  string to_str() {
    return to_time_format(hour)+":"+to_time_format(minute)+":"+to_time_format(second);
  }
// メンバ関数 shift の定義を書く
//   関数名: shift
//   引数: int diff_second
//   返り値: なし
//   関数の仕様:
//     diff_second 秒だけメンバ変数が表す時刻を変更する(ただし、日付やうるう秒は考えない)
//     diff_second の値が負の場合、時刻を戻す
//     diff_second の値が正の場合、時刻を進める
//     diff_second の値は -86400 ~ 86400 の範囲を取とりうる
  void shift(int diff_second) {
    int current_time_second = hour*3600+minute*60+second;
    if (current_time_second+diff_second < 0) diff_second+=86400;
    else if (current_time_second+diff_second >= 86400) diff_second-=86400;
    int abs_diff = abs(diff_second);
    int h = abs_diff/3600;
    int m = (abs_diff-h*3600)/60;
    int s = (abs_diff-h*3600)%60;
    if (diff_second>0) {
      hour+=h;
      minute+=m;
      second+=s;
      if (second>=60){
        minute++;
        second-=60;
      }
      if (minute>=60) {
        hour++;
        minute-=60;
      }
    } else if (diff_second<0) {
      hour-=h;
      minute-=m;
      second-=s;
      if (second<0){
        minute--;
        second+=60;
      }
      if (minute<0) {
        hour--;
        minute+=60;
      }
    }
  }
};

// -------------------
// ここから先は変更しない
// -------------------

int main() {
  // 入力を受け取る
  int hour, minute, second;
  cin >> hour >> minute >> second;
  int diff_second;
  cin >> diff_second;

  // Clock構造体のオブジェクトを宣言
  Clock clock;

  // set関数を呼び出して時刻を設定する
  clock.set(hour, minute, second);

  // 時刻を出力
  cout << clock.to_str() << endl;

  // 時計を進める(戻す)
  clock.shift(diff_second);

  // 変更後の時刻を出力
  cout << clock.to_str() << endl;
}

