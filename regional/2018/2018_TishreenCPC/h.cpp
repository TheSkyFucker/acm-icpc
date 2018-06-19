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
const int N = 1e5 + 7;
int n, far[N], sz[N], a, b;
vi g[N];
void dfs(int u, int fa) {
	sz[u] = 1;
	far[u] = fa;
	for (auto v : g[u]) {
		if (v == fa) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
}
void solve() {
	cin >> n >> a >> b; a--; b--;
	rep(i, 0, n) g[i].clear();
	rep(i, 1, n) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(a, -1);
	vi v;
	do {
		v.pb(sz[b]);
		b = far[b];
	}	while (~b);
	ll ans = 0;
	rep(i, 0, sz(v) - 1) {
		ans += v[i] * 1ll * (v[i + 1] - v[i]);
	}
	cout << ans << endl;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
  int tcas; cin >> tcas;
  rep(cas, 0, tcas) solve();
	return 0;
}
