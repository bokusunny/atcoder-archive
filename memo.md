## Contest Objectives
2021 2nd quarter
- 緑コーダーになる
- [レッドコーダーが教える、競プロ・AtCoder上達のガイドライン【中級編：目指せ水色コーダー！】](https://qiita.com/e869120/items/eb50fdaece12be418faa#2-1-%E6%B0%B4%E8%89%B2%E3%82%B3%E3%83%BC%E3%83%80%E3%83%BC%E3%81%A7%E8%A6%81%E6%B1%82%E3%81%95%E3%82%8C%E3%82%8B-4-%E3%81%A4%E3%81%AE%E3%81%93%E3%81%A8)の基準を満たす
  - AtCoder Beginner Contest で確率 8 割以上で 4 問正解できる
  - AtCoder Beginner Contest で確率 3-4 割で 5 問正解できる
  - AtCoder Beginner Contest の問題をある程度早く解くことができる
    - 目安は、A 問題 1 分、B 問題 4 分、C 問題 10 分、D 問題 25 分
## Next Action
差し当たり、インプット(未修領域学習)とアウトプット(典型問題演習)のハイブリッド。インプットが終わるまではコンテストに特化した対策はしない。焦らず！
- [ ] コード入力速度改善
  - [ ] タイピングの癖直す
  - [ ] 毎日寿司打
  - [ ] バーチャルコンテストで速解き
- [ ] 基本アルゴリズム・データ構造の未修領域を全て学ぶ
  - [ ] [区間DP](http://kutimoti.hatenablog.com/entry/2018/03/10/220819)
  - [x] [bitDP](https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361#11-bit-dp)
  - [x] ワーシャルフロイド法
  - [ ] クラスカル法
- [ ] 典型問題演習
  - [ ] [精選100問](https://qiita.com/e869120/items/eb50fdaece12be418faa#2-3-%E5%88%86%E9%87%8E%E5%88%A5%E5%88%9D%E4%B8%AD%E7%B4%9A%E8%80%85%E3%81%8C%E8%A7%A3%E3%81%8F%E3%81%B9%E3%81%8D%E9%81%8E%E5%8E%BB%E5%95%8F%E7%B2%BE%E9%81%B8-100-%E5%95%8F)
  - [ ] [Educational DP contest](https://qiita.com/drken/items/03c7db44ccd27820ea0d)
  - [ ] [典型90題](https://github.com/E869120/kyopro_educational_90)
  - [ ] [AtCoder Problems 緑diff以上](https://kenkoooo.com/atcoder/#/table/bokusunny)

## Contest Tips
- 変数は問題文に出ているX,A,Bなどのラベルをそのまま使わない、意味のあるラベリングをする。
- PyPyでTLE, MLEが出たらPython3で試してみる
### C問題
- 探索ゴリ押しでいけるが、ひらめきがあれば一瞬で解けることもある。
- まずスマートに解けるかしばし逡巡し、5~10分くらい目安で思いつかなかったら地道な探索で解く方向で行くのがいいか？
- エッジケースの検証を忘れずに

## 履修済み項目一覧
最終更新2021/4/21
()内は人に説明できるレベルの理解か怪しいor未演習

### データ構造
- スタック
- キュー
- 線形リスト
- 木構造
  - 二分木
    - full binary tree
    - complete binary tree
  - ヒープ
  - Union-Find木
  - (セグメント木)
  <!-- - Binary indexed tree -->
- グラフ
  - ダイクストラ法 `O(ElogV)`
  - ワーシャルフロイド法
  <!-- - (クラスカル法) -->

### 探索(サーチ)
- 全探索
  - 順列全探索 `O(NN!)`
  - bit全探索 `O(2^N)`
  - DFS(深さ優先探索) `O(N+M)`
  - BFS(幅優先探索) `O(N+M)`
- 二分探索 `O(logN)`
- (半分全列挙)

### 整列(ソート)
Coming soon

### 累積和
- 累積和(`O(N)`)
- 尺取り法(`O(N)`)
- いもす法

### 整数
- GCD, LCM(最大公約数, 最小公倍数)
  - ユークリッドの互除法とその拡張(大きい方の数をNとすると、おおよそ `O(logN))`)
- 素数
  - 素数判定(`O(sqrt(N)))`)
  - 素数数え上げ
    - ノーマルな解法の場合、`O(Nsqrt(N))`
    - エラトステネスの篩を用いた場合、`O(NloglogN)`
  - 素因数分解
    - ノーマルな解法の場合、Q回のクエリに対して `O(Qsqrt(N))`
    - SPFを利用した場合、 `O(NloglogN+QlogN)`
- (剰余の世界における、逆元を用いた大きい数の除算)
- 繰り返し自乗法(指数Nに対して `O(logN)`)

### 動的計画法(DP)
- ナップザックDP
<!-- - (区間DP) -->
- (bit DP)

<!-- ### その他 -->
<!-- - 座標圧縮 -->
