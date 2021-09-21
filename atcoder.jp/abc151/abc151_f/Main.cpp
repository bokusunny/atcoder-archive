#include <bits/stdc++.h>
using namespace std;

// base
const double EPS = 1e-10;
bool eq(double a, double b) { return abs(a - b) < EPS; }

// Vector
using Vector = complex<double>;
using Vectors = vector<Vector>;
istream &operator>>(istream &is, Vector &v) {
  double a, b;
  is >> a >> b;
  v = Vector(a, b);
  return is;
}
ostream &operator<<(ostream &os, Vector &v) { return os << fixed << setprecision(10) << v.real() << " " << v.imag(); }
Vector rotate(const Vector &v, const double &d) { return v * polar(1.0, d); }

// Circle
struct Circle {
  Vector v;
  double r;

  Circle(Vector &v, double &r) : v(v), r(r) {}
};
using Circles = vector<Circle>;

// 0: 内包 1: 内接 2: 交わる 3: 外接 4: 離れている
int intersect(Circle c1, Circle c2) {
  if (c1.r < c2.r) swap(c1, c2);
  auto dist = abs(c1.v - c2.v);
  if (eq(c1.r + c2.r, dist)) return 3;
  if (eq(c1.r - c2.r, dist)) return 1;
  if (c1.r + c2.r < dist) return 4;
  if (c1.r - c2.r < dist) return 2;
  return 0;
}

pair<Vector, Vector> crosspoints(const Circle &c1, const Circle &c2) {
  assert(1 <= intersect(c1, c2) && intersect(c1, c2) <= 3);
  auto dist = abs(c1.v - c2.v);
  double a = acos((c1.r * c1.r + dist * dist - c2.r * c2.r) / (2 * c1.r * dist));
  double t = atan2(c2.v.imag() - c1.v.imag(), c2.v.real() - c1.v.real());
  Vector p1 = c1.v + Vector(cos(t + a) * c1.r, sin(t + a) * c1.r);
  Vector p2 = c1.v + Vector(cos(t - a) * c1.r, sin(t - a) * c1.r);
  return make_pair(p1, p2);
}

void solve() {
  int N;
  cin >> N;
  Vectors V(N);
  for (int i = 0; i < N; i++) cin >> V[i];

  auto is_ok = [&](double r) {
    Circles C;
    for (int i = 0; i < N; i++) C.emplace_back(V[i], r);

    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if (intersect(C[i], C[j]) == 4) return false;
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        auto [v1, v2] = crosspoints(C[i], C[j]);
        bool ok1 = true, ok2 = true;
        for (auto &v : V) {
          if (!eq(abs(v1 - v), r) && abs(v1 - v) > r) ok1 = false;
          if (!eq(abs(v2 - v), r) && abs(v2 - v) > r) ok2 = false;
        }
        if (ok1 || ok2) return true;
      }
    }

    return false;
  };

  double ng = 0.0, ok = 2000.0;
  while (abs(ok - ng) > EPS) {
    double mid = (ok + ng) / 2;
    if (is_ok(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << setprecision(15) << ok << endl;
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
