// index : [0, nx), [0, ny)
// time : O(E*sqrt(V))
// !!!! : ini() before use
struct Hopcroft {
	static const int N = 3e3 + 7;
	vi g[N];
	int px[N], mx[N], nx;
	int py[N], my[N], ny;
	int ini(int _nx, int _ny) {
		fill_n(mx, nx = _nx, -1);
		fill_n(my, ny = _ny, -1);
		rep(i, 0, _nx) g[i].clear();
	}
	void link(int a, int b) { g[a].pb(b); }
	int trace(int y) {
		int x = py[y], yy = px[x];
		py[y] = px[x] = -1;
		if (!~mx[x] || (~yy && trace(yy)))
			return mx[x] = y, my[y] = x, 1;
		return 0;
	}
	bool bfs() {
		fill_n(px, nx, -1);
		fill_n(py, ny, -1);
		queue<int> q;
		rep(x, 0, nx) if (!~mx[x]) q.push(x);
		bool ret = false;
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (auto y : g[x]) if (!~py[y]) {
				py[y] = x;
				if (!~my[y]) ret = true;
				else q.push(my[y]), px[my[y]] = y;
			}
		}
		return ret;
	}
	int solve() {
		int ret = 0;
		while (bfs())
			rep(y, 0, ny) if (!~my[y] && ~py[y])
				ret += trace(y);
		return ret;
	}
} hug;