// index : [0, nx), [0, ny)
// time : O(V ^ 3) | O(VE)
// !!!! : ini() && nx <= ny
const int INF = 1e9 + 7;
struct KM {
	static const int N = 5e2 + 7;
	int nx, ny;
	bool vis[N];
	int lx[N], ly[N], my[N];
	int p[N], ned[N], g[N][N];
	void ini(int _nx, int _ny) {
		assert(_nx <= _ny);
		fill_n(lx, nx = _nx, 0);
		fill_n(ly, ny = _ny, 0);
		fill_n(my, ny, -1);
		rep(i, 0, nx)
			fill_n(g[i], ny, -INF);
	}
	void link(int x, int y, int v) { g[x][y] = v; }
	void gao(int x) {
		rep(y, 0, ny + 1) vis[y] = 0, ned[y] = INF;
		int u = ny;
		my[u] = x;
		while (~my[u]) {
			vis[u] = true;
			int d = INF, v;
			rep(y, 0, ny) {
				if (!vis[y]) {
					int tmp = lx[my[u]] + ly[y] - g[my[u]][y];
					if (ned[y] > tmp)
						ned[y] = tmp, p[y] = u;
					if (ned[y] < d) d = ned[v = y];
				}
			}
			rep(y, 0, ny + 1) 
				if (vis[y]) lx[my[y]] -= d, ly[y] += d;
				else ned[y] -= d;
			u = v;
		}
		for (; u != ny; u = p[u]) my[u] = my[p[u]];
	}
	int solve() {
		rep(i, 0, nx) gao(i);
		int ret = 0;
		rep(i, 0, nx) ret += lx[i];
		rep(i, 0, ny) ret += ly[i];
		return ret;
	}
}	hug;