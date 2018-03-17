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
const int N = 2e5 + 7;
int x[N], d[N], t[N], p[N];
vector<tuple<int, int, int> > g[N];

ll dis[N];
pii pre[N];
void spfa(int S, int n) {
	priority_queue<pair<ll, int> > stk;
	fill_n(dis, n, LLONG_MAX); dis[S] = 0;
	stk.push({-dis[S], S});
	while (!stk.empty()) {
		auto u = stk.top(); stk.pop();
		u.fi = -u.fi;
		if (dis[u.se] != u.fi) continue;
		for (auto e : g[u.se]) {
			int v, w, id;
			tie(v, w, id) = e;
			if (dis[v] > u.fi + w) {
				dis[v] = u.fi + w;
				pre[v] = {u.se, id};
				stk.push({-dis[v], v});
			}
		}
	}
}

int n, L;
int main() {
	scanf("%d%d", &n, &L);
	vi tx; tx.pb(0); tx.pb(L);
  rep(i, 0, n) {
  	scanf("%d%d%d%d", x + i, d + i, t + i, p + i);
		if (x[i] - p[i] >= 0) {
			tx.pb(x[i] - p[i]);
			tx.pb(x[i] + d[i]);
		}
	}
	sort(all(tx));
	tx.erase(unique(all(tx)), tx.end());
	rep(i, 0, sz(tx) - 1) {
		g[i].pb(make_tuple(i + 1, tx[i + 1] - tx[i], -1));
		g[i + 1].pb(make_tuple(i, tx[i + 1] - tx[i], -1));
	}
	rep(i, 0, n) {
		if (x[i] - p[i] >= 0) {
			int a = lower_bound(all(tx), x[i] - p[i]) - tx.begin();
			int b = lower_bound(all(tx), x[i] + d[i]) - tx.begin();
			g[a].pb(make_tuple(b, t[i] + p[i], i));
		}
	}
	spfa(0, sz(tx));
	vi ans;
	for (int u = sz(tx) - 1; u; u = pre[u].fi) {
		if (~pre[u].se) ans.pb(pre[u].se);
	}
	printf("%lld\n", dis[sz(tx) - 1]);
	printf("%d\n", sz(ans));
	per(i, 0, sz(ans)) {
		printf("%d\n", ans[i] + 1);
	}
	return 0;
}
