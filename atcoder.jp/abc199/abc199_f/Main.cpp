#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

template <class T>
struct Matrix {
 private:
  vector<vector<T>> A;

 public:
  Matrix(const int &r, const int &c) : A(r, vector<T>(c, 0)) {}
  Matrix(const int &n) : A(n, vector<T>(n, 0)) {}

  int row_size() const { return (int)A.size(); }
  int column_size() const { return (int)A[0].size(); }

  static Matrix I(int n) {
    Matrix res(n);
    for (int i = 0; i < n; i++) res[i][i] = 1;
    return res;
  }

  inline const vector<T> &operator[](int r) const {
    assert(0 <= r && r < row_size());
    return A[r];
  }
  vector<T> &operator[](int r) {
    assert(0 <= r && r < row_size());
    return A[r];
  }
  Matrix &operator+=(const Matrix &B) {
    int ra = row_size(), ca = column_size();
    int rb = B.row_size(), cb = B.column_size();
    assert(ra == rb && ca == cb);

    for (int i = 0; i < ra; i++) {
      for (int j = 0; j < ca; j++) {
        (*this)[i][j] += B[i][j];
      }
    }
    return (*this);
  }
  Matrix &operator-=(const Matrix &B) {
    int ra = row_size(), ca = column_size();
    int rb = B.row_size(), cb = B.column_size();
    assert(ra == rb && ca == cb);

    for (int i = 0; i < ra; i++) {
      for (int j = 0; j < ca; j++) {
        (*this)[i][j] -= B[i][j];
      }
    }
    return (*this);
  }
  Matrix &operator*=(const Matrix &B) {
    int ra = row_size(), ca = column_size();
    int rb = B.row_size(), cb = B.column_size();
    assert(ca == rb);

    vector C(ra, vector<T>(cb, 0));
    for (int i = 0; i < ra; i++) {
      for (int j = 0; j < cb; j++) {
        for (int k = 0; k < ca; k++) {
          C[i][j] += (*this)[i][k] * B[k][j];
        }
      }
    }
    A.swap(C);
    return (*this);
  }
  Matrix &operator^=(long long k) {
    Matrix B = Matrix::I(row_size());
    while (k > 0) {
      if (k & 1) B *= *this;
      *this *= *this;
      k >>= 1;
    }
    A.swap(B.A);
    return (*this);
  }
  Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }

  Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }

  Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }

  Matrix operator^(const long long k) const { return (Matrix(*this) ^= k); }

  friend ostream &operator<<(ostream &os, Matrix &Mat) {
    int r = Mat.row_size(), c = Mat.column_size();
    for (int i = 0; i < r; i++) {
      os << "[";
      for (int j = 0; j < c; j++) {
        os << Mat[i][j] << (j + 1 == c ? "]\n" : ",");
      }
    }
    return (os);
  }
};

struct Edge {
  int to;

  Edge(const int to) : to(to) {}
};
using Graph = vector<vector<Edge>>;

void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  Graph G(N);
  for (int i = 0; i < M; i++) {
    int X, Y;
    cin >> X >> Y;
    X--;
    Y--;
    G[X].emplace_back(Y);
    G[Y].emplace_back(X);
  }

  Matrix<mint> MatA(N, 1);
  for (int i = 0; i < N; i++) MatA[i][0] = A[i];
  Matrix<mint> MatC(N, N);
  for (int i = 0; i < N; i++) {
    int d = (int)G[i].size();
    for (auto [j] : G[i]) {
      MatC[i][j] = 1;
      MatC[i][j] /= M * 2;
    }
    MatC[i][i] = 1;
    MatC[i][i] -= (mint)d / M / 2;
  }

  MatC ^= K;
  MatC *= MatA;

  for (int i = 0; i < N; i++) cout << MatC[i][0].val() << endl;
}

void setcin() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  setcin();
  solve();

  return 0;
}
