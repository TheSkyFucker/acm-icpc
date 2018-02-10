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
const int N = 1e2 + 7;
int n, m;
vi g[N];
bool vis[N];
void dfs(int u, vi &v) {
	v.pb(u);
	vis[u] = true;
	for (auto e : g[u]) if (!vis[e]) dfs(e, v);
}

int main() {
	scanf("%d%d", &n, &m);
  rep(i, 0, m) {
  	int a, b; scanf("%d%d", &a, &b);
  	g[a].pb(b);
  	g[b].pb(a);
	}
	vector<vi> vs;
	rep(i, 1, n + 1) if (!vis[i]) {
		vs.pb(vi());
		dfs(i, vs.back());
	}
	vector<vi> vv[4];
	for (auto v : vs) if (sz(v) > 3) { puts("-1"); return 0; }
	for (auto v : vs) vv[sz(v)].pb(v);
	rep(i, 0, sz(vv[2])) {
		auto v = vv[2][i];
		if (vv[1].empty()) { puts("-1"); return 0; }
		v.pb(vv[1].back().back()); vv[1].pop_back();
		vv[3].pb(v);
	}
	while (!vv[1].empty()) {
		vi v;
		rep(i, 0, 3) { v.pb(vv[1].back().back()); vv[1].pop_back(); }
		vv[3].pb(v);
	}
	for (auto v : vv[3]) {
		rep(i, 0, 3) printf("%d%c", v[i], " \n"[i == 2]);
	}

	return 0;
}
