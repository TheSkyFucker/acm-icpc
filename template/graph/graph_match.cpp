// index : [0, n)
// time : O(VE)
// !!!! : ini() before use
struct GraphMatch {
	static const int N = 3e3 + 7;
	vi g[N];
	int p[N], m[N], d[N], n;
	int c1[N], c2[N], v[N];
	int q[N], *qf, *qb;

	void link(int a, int b) { g[a].pb(b); g[b].pb(a); }

	int fa[N];
	int f(int x) { return fa[x] == x ? x : fa[x] = f(fa[x]); }
	void join(int x, int y) { fa[f(x)] = f(y); }

	void ini(int _n) { rep(i, 0, n = _n) g[i].clear(); }
	void match(int i, int j) { m[i] = j; m[j] = i; }

	void path(int r, int x) {
		if (r == x) return; 
		if (d[x] == 0) {
			path(r, p[p[x]]);
			match(p[x], p[p[x]]);
		}
		else {
			path(m[x], c1[x]);
			path(r, c2[x]);
			match(c1[x], c2[x]);
		}
	}

	int lca(int x, int y, int r) {
		static int vs = 0; vs++;
		int i = x, j = y;
		while (1) {
			if (i != r && v[i = f(p[i])] == vs) return i; v[i] = vs;
			if (j != r && v[j = f(p[j])] == vs) return j; v[j] = vs;
		}
	}

	void shrink(int x, int y, int b) {
		for (int i = f(x); i != b; i = f(p[i])) {
			join(i, b);
			if (d[i] == 1) c1[i] = x, c2[i] = y, *qb++ = i;
		}
	}

	bool bfs(int r) {
		rep(i, 0, n) fa[i] = i;
		fill_n(d, n, -1), d[r] = 0;
		qf = qb = q; *qb++ = r;
		while (qf < qb) {
			int x = *qf++;
			for (auto y : g[x]) {
				if (m[y] == y || f(x) == f(y)) continue;
				if (!~d[y]) {
					if (!~m[y]) {
						path(r, x);
						match(x, y);
						return true;
					}
					else {
						p[y] = x; p[m[y]] = y;
						d[y] = 1; d[m[y]] = 0;
						*qb++ = m[y];
					}
				}
				else if (d[f(y)] == 0) {
					int b = lca(x, y, r);
					shrink(x, y, b);
					shrink(y, x, b);
				}
			}
		}
		return false;
	}

	int solve() {
		fill_n(m, n, -1);
		int ret = 0;
		rep(i, 0, n) if (!~m[i]) {
			if (bfs(i)) ret++;
			else m[i] = i;
		}
		return ret;
	}

}	hug;