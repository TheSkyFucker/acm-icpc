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
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----
const int N = 1e6 + 7;

namespace SCC {
	const int N = ::N;
	int bel[N], vis[N];
	vi v, g[N], rg[N];
	vector<vi> scc, ng, rng;
	void dfs1(int u) {
		vis[u] = 1;
		for (auto v : g[u]) if (!vis[v]) dfs1(v);
		v.pb(u);
	}
	void dfs2(int u) {
		bel[u] = sz(scc);
		scc.back().pb(u);
		for (auto v : rg[u]) if (!bel[v]) dfs2(v);
	}
	void solve(int n) {
		rep(u, 0, n) if (!vis[u]) dfs1(u);
		reverse(all(v));
		for (auto u : v) if (!bel[u]) scc.pb(vi()), dfs2(u);
		rep(u, 0, n) bel[u]--;
		ng.resize(sz(scc));
		rng.resize(sz(scc));
		rep(u, 0, n) for (auto v : g[u])
			if (bel[u] != bel[v]) ng[bel[u]].pb(bel[v]);
	}
};

map<string, int> Map;
pii ned[N], nned[N];
int getid(string str) {
	if (!Map.count(str)) {
		int sz = sz(Map);
		auto &d = ned[sz];
		Map[str] = sz;
		rep(i, 0, sz(str)) if (str[i] == 'r') d.fi++;
		d.se = sz(str);
	}
	return Map[str];
}

void tolow(string &str) {
		transform(all(str), str.begin(), ::tolower);
}
int n, m;
string str[N];
int deg[N];
int main() {
	scanf("%d", &n);
	rep(i, 0, n) {
		cin >> str[i];
		tolow(str[i]);
		getid(str[i]);
	}
	using namespace SCC;
	scanf("%d", &m);
	rep(i, 0, m) {
		string a, b; cin >> a >> b;
		tolow(a), tolow(b);
		int ida = getid(a);
		int idb = getid(b);
		g[ida].pb(idb);
		rg[idb].pb(ida);
	}
	int nn = sz(Map);
	solve(nn);
	int sccn = sz(scc);
	rep(i, 0, sccn) nned[i] = {1000000000, 0};
	rep(i, 0, nn) {
		nned[bel[i]] = min(nned[bel[i]], ned[i]);
	}
	rep(i, 0, sccn) for (auto v : ng[i]) {
		rng[v].pb(i);
		deg[i]++;
	}
	queue<int> que;
	rep(i, 0, sccn) if (!deg[i]) que.push(i);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (auto v : rng[u]) {
			nned[v] = min(nned[v], nned[u]); 
			if (!--deg[v]) que.push(v);
		}
	}
	pair<int, ll> ans(0, 0);
	rep(i, 0, n) {
		auto tmp = nned[bel[getid(str[i])]];
		ans.fi += tmp.fi;
		ans.se += tmp.se;
	}
	printf("%d %lld", ans.fi, ans.se);
	return 0;
}
