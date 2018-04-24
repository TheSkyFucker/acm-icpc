// index : [0, nx), [0, ny)
// time : O(VE)
// !!!! : ini() before use
struct Hug {
	static const int N = 3e3 + 7;
	vi g[N];
	int my[N], vis[N], nx, ny;
	void ini(int _nx, int _ny) {
		nx = _nx, ny = _ny;
		rep(i, 0, nx) g[i].clear();
	}
	void link(int a, int b) { 
		g[a].pb(b); 
	}
	bool find(int x) {
		for (auto y : g[x]) if (!vis[y]) {
			vis[y] = 1;
			if (!~my[y] || find(my[y])) return my[y] = x, true;
		}
		return false;
	}
	int solve() {
		int ret = 0;
		fill_n(my, ny, -1);
		rep(i, 0, nx) {
			fill_n(vis, ny, 0);
			ret += find(i);
		}
		return ret;
	}
}	hug;