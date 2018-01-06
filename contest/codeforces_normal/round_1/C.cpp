#include<bits/stdc++.h>
using namespace std;
typedef long double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//------
const db eps = 1e-3, pi = acos(-1.);
int sgn(db x) { return (x > eps) - (x < -eps); }
typedef db T;
struct P {
	T x, y;
	P() {} P (T x, T y) : x(x), y(y) {}
	P operator -(const P&b) const { return P(x - b.x, y - b.y); }
	P operator +(const P&b) const { return P(x + b.x, y + b.y); }
	T operator *(const P&b) const { return x * b.x + y * b.y; }
	T operator /(const P&b) const { return x * b.y - y * b.x; }
	P operator *(const T&k) const { return P(x * k, y * k); }
	void read() { double _x, _y; scanf("%lf%lf", &_x, &_y); x = _x, y = _y; }
	//void show() { printf("x = %.2f, y = %.2f\n", x, y); }
};
T abs(P a) { return sqrt(a.x * a.x + a.y * a.y); }
struct L {
	P s, t;
	L() {}
	L(P s, P t) : s(s), t(t) {}
};
P insLL(L a, L b) {
	P s = a.s - b.s, v = a.t - a.s, w = b.t - b.s;
	db k1 = s / w, k2 = w / v;
	if (sgn(k2) == 0) return abs(b.s - a.s) < abs(b.t - a.s) ? b.s : b.t;
	return a.s + v * (k1 / k2);
}

P a[10]; int id[3];
L getl(P p1, P p2) {	
	P s1 = (p1 + p2) * 0.5;
	P s2;
	if (sgn(p1.y - p2.y) == 0) s2 = P(s1.x, s1.y + 1.);
	else s2 = P(s1.x + 1., s1.y + (p2.x - p1.x) / (p1.y - p2.y));
	return L(s1, s2);
}

bool ok(db ned, db per) {
	ll tim = (ned / per + eps);
	return sgn(tim * per - ned) == 0;
}

db gao() {
	L l1 = getl(a[id[0]], a[id[1]]); //l1.s.show(); l1.t.show();
	L l2 = getl(a[id[1]], a[id[2]]);
	P o = insLL(l1, l2);
	//o.show();
	db r = abs(o - a[id[0]]);
	db r1 = abs(o - a[id[1]]);
	db r2 = abs(o - a[id[2]]);
	assert(sgn(r - r1) == 0);
	assert(sgn(r - r2) == 0);
	db ang1 = asin(abs(a[id[1]] - a[id[0]]) / 2. / r) * 2.;
	db ang2 = asin(abs(a[id[2]] - a[id[1]]) / 2. / r) * 2.;
	rep(i, 3, 101) {
		db per = 2. * pi / i;
		if (ok(ang1, per) && ok(ang2, per)) {
			db an = 2. * r * sin(per / 2.);
			db rn = r * cos(per / 2.);
			db pn = i * an;
			db sn = pn * rn / 2.;
			return sn;
		}
	}
	return 1e18;
}

int main() {
	rep(i, 0, 3) a[i].read();
	rep(i, 0, 3) id[i] = i;
	db ans = 1e18;
	do {
		ans = min(ans, gao());
	} while (next_permutation(id, id + 3));
	printf("%.10f\n", (double)ans);
	return 0;
}
