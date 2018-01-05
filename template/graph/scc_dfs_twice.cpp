//index : [0, n]
//bel[i] : which SCC i-th node belong to
namespace SCC {
	const int N = ::N;
	int bel[N], vis[N];
	vi v, g[N], rg[N];
	vector<vi> scc, ng;
	void dfs1(int u) {
		vis[u] = 1; 
		for (auto v :  g[u]) if (!vis[v]) dfs1(v); 
		v.pb(u); 
	}
	void dfs2(int u) { 
		bel[u] = sz(scc); 
		scc.back().pb(u);
		for (auto v : rg[u]) if (!bel[v]) dfs2(v); 
	}
	void solve(int n) {
		scc.clear(); ng.clear(); v.clear();
		fill_n(vis, n, 0);
		fill_n(bel, n, 0);
		rep(u, 0, n) if (!vis[u]) dfs1(u);
		reverse(all(v));
		for (auto u : v) if (!bel[u]) scc.pb(vi()), dfs2(u);
		rep(u, 0, n) bel[u]--;
		ng.resize(sz(scc));
		rep(u, 0, n) for (auto v : g[u])
			if (bel[u] != bel[v]) ng[bel[u]].pb(bel[v]); 
	}
};
