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
//time O(VE)
//index [0, n)
//how to use: init(n) -> add edge to E -> gao()
typedef long long T;
struct Edge {
	T u, v, w;
	Edge(){} Edge(T u, T v, T w) : u(u), v(v), w(w) {}
};
struct Bellman_ford {
	static const int N = 1e3 + 7;
	static const T INF = 1e18 + 7; //! depend on T
	T d[N];
	int n, p[N];
	vector<Edge> E;
	void init(int _n) { 
		n = _n; E.clear();
		fill_n(p, n, -1);
		fill_n(d, n, INF);
	}
	bool gao(int s) { //false: has nag-circle
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

int n, m;
void solve() {
	bf.init(n);
	rep(i, 0, m) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c); a--; b--;
		bf.E.pb(Edge(a, b, c));
		bf.E.pb(Edge(b, a, c));
	}
	bf.gao(0);
	printf("%lld\n", bf.d[n - 1]);
}


int main() {
	while (~scanf("%d%d", &n, &m) && n && m) solve();
	return 0;
}
