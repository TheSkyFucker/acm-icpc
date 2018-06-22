// desc : 'a' .. 'z' | 0 is root | N-1 is virtual
// !!!! : ini() -> ins() -> bud()
struct ACA {
	static const int N = ::N, M = 26;
	int nxt[N][M], fail[N], fa[N], _;
	int ne() { fill_n(nxt[_], M, 0); return _++; }
	void ini() { fail[_ = 0] = N - 1; ne(); }
	void ins(string s) {
		int u = 0;
		rep(i, 0, sz(s)) {
			int &v = nxt[u][s[i] - 'a']; // modify
			if (!v) fa[v = ne()] = u;
			u = v;
		}
	}
	void bud() {
		vi v; v.pb(0);
		rep(_u, 0, sz(v)) {
			int u = v[_u];
			rep(i, 0, M) nxt[u][i] 
				? v.pb(nxt[u][i]), fail[nxt[u][i]] = nxt[fail[u]][i]
				: nxt[u][i] = nxt[fail[u]][i];
		}
	}
}	ac;
