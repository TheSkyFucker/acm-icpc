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
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << (x) << ", "
#define de(x) cout << #x << " = " << (x) << endl
//-----
const db pi = acosl(-1.0);
typedef db T;
struct P {
	T x, y;
	P(){}P(T x, T y) : x(x), y(y) {}
	void read() { double _x, _y; scanf("%lf%lf", &_x, &_y); x = _x; y = _y; }
	P operator +(const P &b) const { return P(x + b.x, y + b.y); }
	P operator -(const P &b) const { return P(x - b.x, y - b.y); }
	P operator *(const T &d) const { return P(x * d, y * d); }
	P operator /(const T &d) const { return P(x / d, y / d); }
	T operator *(const P &b) const { return x * b.x + y * b.y; }
	T operator /(const P &b) const { return x * b.y - y * b.x; }
	//P rot(const T &a) const { return P(cosl(a) * x - sinl(a) * y, sinl(a) * x + cosl(a) * y); } //逆时针
	T norm() const { return (*this) * (*this); }
	T abs() const { return sqrt(norm()); }
	T ang() const { return atan2(y, x); }
};

T get_ang(const P& p) { return - (p.ang() + pi / 2.); }

typedef vector<P> polygon;
P gravity(polygon p) {
	P o = p[0], g(0, 0);
	rep(i, 0, sz(p)) p[i] = p[i] - o;
	p.pb(p[0]);
	T area = 0;
	rep(i, 0, sz(p) - 1) {
		T tmp = p[i] / p[i + 1];
		g = g + (p[i] + p[i + 1]) * tmp;
		area += tmp;
	}
	return g / (3. * area) + o;
}

const int N = 1e4 + 7;
int n, q;
T tot_ang = 0.;
T ang[N], dis[N];

polygon p;
P g;
P get_real(int id) {
	T ang = ::ang[id] + tot_ang;
	return P(cos(ang) * dis[id], sin(ang) * dis[id]);
}

int main() {
	scanf("%d%d", &n, &q);
	p.resize(n);
	rep(i, 0, n) p[i].read();
	g = gravity(p);
	rep(i, 0, n) {
		p[i] = p[i] - g;
		ang[i] = p[i].ang();
		dis[i] = p[i].abs();
	}
	
	int p1 = 0, p2 = 1;
	rep(i, 0, q) {
		int op; scanf("%d", &op);
		if (op == 2) {
			int id; scanf("%d", &id), id--;
			P ans = get_real(id) + g;
			printf("%.16f %.16f\n", double(ans.x), double(ans.y));
		}
		else {
			int f, t; scanf("%d%d", &f, &t), f--, t--;
			if (p1 == f) swap(p1, p2);
			p2 = t;
			P pivot = get_real(p1);
			tot_ang += get_ang(pivot) + pi;
			while (tot_ang > 2. * pi) tot_ang -= 2. * pi;
			while (tot_ang < 0) tot_ang += 2. * pi;
			g = g + P(pivot.x, pivot.y - dis[p1]);
		}
	}
	
	return 0;
}
