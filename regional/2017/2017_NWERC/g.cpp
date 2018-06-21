#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,l,r) for(int i=(r)-1;i>=(l);i--)
#define dd(x) cout << #x << " = " << (x) << ", "
#define de(x) cout << #x << " = " << (x) << "\n"
#define endl "\n"

//-----
const int N = 1e3 + 7;
typedef db T;
T eps = 1e-10, pi = acos(-1.0);
int sgn(T d) { return (d > eps) - (d < -eps); }
struct P {
	T x, y;
	P(){} P(T x, T y) : x(x), y(y) {}
	void read() { cin >> x >> y; }
	void out() { dd(x); de(y); }
	T operator *(const P&b) { return x * b.x + y * b.y; }
	T operator /(const P&b) { return x * b.y - y * b.x; }
	P operator -(const P&b) { return P(x - b.x, y - b.y); }
	P rot(const T &a) const { return P(cos(a) * x - sin(a) * y, sin(a) * x + cos(a) * y); }
};
db S(int x, db d) {
	db h = cos(pi / x) * d;
	return x * h * d;
}
bool onPS(P p, P s, P t) { return sgn((t - s) / (p - s)) == 0 && sgn((p - s) * (p - t)) <= 0; }

typedef vector<P> polygon;
int operator <(P p, polygon A) {
	int res = 0;
	rep(i, 0, sz(A)) {
		P u = A[i], v = A[(i + 1) % sz(A)];
		if (onPS(p, u, v)) return -1;
		T cross = sgn((v - u) / (p - u)), d1 = sgn(u.y - p.y), d2 = sgn(v.y - p.y);
		if (cross > 0 && d1 <= 0 && d2 > 0) ++ res;
		if (cross < 0 && d2 <= 0 && d1 > 0) -- res;
	}
	return res;
}
int n;
P b[N];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	rep(i, 0, n) b[i].read();
	pair<db, int> ans = {-1., 0};
	rep(i, 3, 9) {
		db a = 2. * pi / i;
		db d[2];
		rep(_, 0, 2) {
			db l = 0., r = 1e9;
			rep(j, 0, 100) {
				db mid = (l + r) / 2.;
				bool ok = true;
				polygon po(i);
				po[0] = P(mid, 0);
				rep(k, 1, i) po[k] = po[k - 1].rot(a);
				if (_ == 0) {
					rep(k, 0, n) if (b[k] < po) {
						ok = false; break;
					}
					ok ? l = mid : r = mid;
				}
				else {
					rep(k, 0, n) if (!(b[k] < po)) {
						ok = false; break;
					}
					ok ? r = mid : l = mid;
				}
			}
			d[_] = (l + r) / 2.;
		}
		ans = max(ans, {d[0] * d[0] / d[1] / d[1], i});
	}
	cout.precision(10);
	cout << ans.se << " " << ans.fi;
	return 0;
}
