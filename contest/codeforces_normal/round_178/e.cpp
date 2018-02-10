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
const int N = 5e3 + 7;
int n;
vector<pii> g[N];

ll sz[N], Sz, dn[N], up[N], Tmp, Min;

void dfs_dn(int u, int fa) {
	dn[u] = up[u] = 0, sz[u] = 1;
	for (auto e : g[u]) if (e.fi != fa) {
		int v = e.fi;
		dfs_dn(v, u);
		sz[u] += sz[v];
		dn[u] += dn[v] + sz[v] * e.se;
	}
}

void dfs_up(int u, int fa) {
	Min = min(Min, dn[u] + up[u]);
	for (auto e : g[u]) if (e.fi != fa) {
		int v = e.fi;
		Tmp += e.se * sz[v] * (Sz - sz[v]);
		up[v] = dn[u] + up[u] - (dn[v] + sz[v] * e.se) + (Sz - sz[v]) * e.se;
		dfs_up(v, u);
	}
}

pair<ll, ll> gao(int u, int v) {
	Tmp = 0; Min = pw(60);
	dfs_dn(u, v); Sz = sz[u];
	dfs_up(u, v);
	return mp(Tmp, Min);
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		g[a].pb({b, c});
		g[b].pb({a, c});
	}
	ll ans = pw(60);
	rep(u, 0, n) {
		for (auto e : g[u]) {
			int v = e.fi; if (v < u) continue;
			auto itu = gao(u, v);
			auto itv = gao(v, u);
			ll tmp = itu.fi + itv.fi + itu.se * Sz + itv.se * (n - Sz) + Sz * (n - Sz) * e.se;
			ans = min(ans, tmp);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
