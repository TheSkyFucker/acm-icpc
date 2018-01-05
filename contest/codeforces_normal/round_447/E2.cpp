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
const int N = 1e6 + 6;
int n, m, S, sn, deg[N];
ll val[N], dis[N];
ll sum1(ll x) { return x * (x + 1) / 2; }
ll sum2(ll x) { return x * (x + 1) * (2 * x + 1) / 6; }
ll getv(int l) {
	int mxi = sqrt(2 * l); while (mxi * (mxi + 1) > 2 * l) mxi--;
	return (mxi + 1ll) * l - (sum1(mxi) + sum2(mxi)) / 2;
}

namespace SCC {
	const int N = ::N;
	int bel[N], vis[N];
	vi v, g[N], rg[N], gw[N];
	vector<vi> scc;
	vector<vector<pii> > ng;
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
		ng.resize(sz(scc)); sn = sz(scc);
		fill_n(val, sn, 0);
		fill_n(deg, sn, 0);
		rep(u, 0, n) rep(_v, 0, sz(g[u])) {
			int v = g[u][_v];
			if (bel[u] == bel[v]) val[bel[u]] += getv(gw[u][_v]);
			else ng[bel[u]].pb({bel[v], gw[u][_v]}), deg[bel[v]]++;
		}
	}
};

void solve() {
	using namespace SCC;
	rep(i, 0, n) g[i].clear(), rg[i].clear(), gw[i].clear();
	rep(i, 0, m) {
		int a, b, w; scanf("%d%d%d", &a, &b, &w); a--; b--;
		g[a].pb(b);
		rg[b].pb(a);
		gw[a].pb(w);
	}
	solve(n);
	scanf("%d", &S); S = bel[S - 1];
	fill_n(dis, n, -1); dis[S] = val[S];
	queue<int> que;
	rep(i, 0, sn) if (!deg[i]) que.push(i);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (auto _v : ng[u]) {
			if (~dis[u] && dis[_v.fi] < dis[u] + _v.se + val[_v.fi])
				dis[_v.fi] = dis[u] + _v.se + val[_v.fi];
			if (!--deg[_v.fi]) que.push(_v.fi);
		}
	}
	ll ans = 0; rep(i, 0, sn) ans = max(ans, dis[i]);
	printf("%lld\n", ans);
}
	

int main() {
	while (~scanf("%d%d", &n, &m)) solve();
	return 0;
}
