#include<bits/stdc++.h>
using namespace std;
typedef double db;
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
const int N = 2e3 + 7;
//time O(VE)
//index [0, n)
//how to use: init(n) -> add edge to E -> gao()
typedef long long T;
struct Edge {
	T u, v, w;
	Edge(){} Edge(T u, T v, T w) : u(u), v(v), w(w) {}
};
struct Bellman_ford {
	static const int N = ::N;
	static const T INF = 1e18 + 7; //! depend on T
	T d[N];
	int n, p[N];
	vector<Edge> E;
	void init(int _n) { 
		n = _n; E.clear();
		fill_n(p, n, -1);
		fill_n(d, n, INF);
	}
	void adde(Edge e) { E.pb(e); }
	bool gao(int s) { //false: has nag-circle
//		de(sz(E));
		d[s] = 0;
		rep(i, 0, n) for (auto e : E) {
			if (d[e.v] > d[e.u] + e.w) {
				d[e.v] = d[e.u] + e.w;
				p[e.v] = e.u;
			}
		}
		for (auto e : E) if (d[e.v] > d[e.u] + e.w) return false;
		return true;
	}
	vi path(int t) { //should make sure [has path] && [not nag-circle]
		vi r; for (; ~t; t = p[t]) r.pb(t);
		reverse(all(r));
		return r;
	}
}	bf;

int n, m, x;
ll t[N];
void solve() {
	scanf("%d%d%d", &n, &m, &x);
	bf.init(n);
	rep(i, 0, m) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		if (a == b) {
			if (c == d) {
				bf.adde(Edge(a - 1, c - 1, x));
				bf.adde(Edge(c - 1, a - 1, -x));
			}
			else {
				bf.adde(Edge(a - 1, c - 1, x - 1));
				bf.adde(Edge(c, a - 1, -x - 1));
			}
		}
		else {
			if (c == d) {
				bf.adde(Edge(c - 1, a - 1, -x - 1));
				bf.adde(Edge(a, c - 1, x - 1));
			}
			else {
				bf.adde(Edge(a, c - 1, x - 1));
				bf.adde(Edge(c, a - 1, -x - 1));
			}
		}
	}
	rep(i, 1, n) {
		bf.adde(Edge(i, i - 1, -1));
	}
	if (!bf.gao(n - 1)) {
		puts("IMPOSSIBLE");
		return;
	}
//	for (auto e : bf.E) { dd(e.u); dd(e.v); de(e.w); }
	rep(i, 1, n) {
		t[i] = bf.d[i] - bf.d[i - 1];
		if (t[i] > 2000000000) {
			puts("IMPOSSIBLE");
			return;
		}
	}
	rep(i, 1, n) printf("%d%c", t[i], " \n"[i == n - 1]);
}

int main() {
	int tcase = 0; scanf("%d", &tcase);
	rep(icase, 1, tcase + 1) {
		printf("Case #%d: ", icase);
		solve();
	}
	return 0;
}
