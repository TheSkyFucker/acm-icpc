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
	bool gao(int s) { //return false: has nag-circle
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


