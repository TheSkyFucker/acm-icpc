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
const int N = 1e4 + 7, K = 1e2 + 7;
int n, m, k;
vector<pii> g[2][N];
void gao(int d, vi &v) {
	for (int i = 2; i * i <= d; i ++) {
		if (d % i == 0) {
			v.pb(i);
			while (d % i == 0) d /= i;
		}
	}
	if (d> 1) v.pb(d);
}
ll dis[N][K];
bool in[N][K];
void spfa(int S) {
	rep(i, 0, n) fill_n(dis[i], k, LLONG_MAX); 
	dis[S][0] = 0; in[S][0] = true;
	queue<pii> que; que.push({S, 0});
	while (!que.empty()) {
		int uu, uk;
		tie(uu, uk) = que.front(); que.pop();
		for (auto e : g[0][uu]) {
			if (dis[e.fi][uk] > dis[uu][uk] + e.se) {
				dis[e.fi][uk] = dis[uu][uk] + e.se;
//				if (e.fi == 3 && uk == 0 && dis[e.fi][uk] == 42) {}
				if (!in[e.fi][uk]) {
					in[e.fi][uk] = true;
					que.push({e.fi, uk});
				}
			}
		}
		if (uk + 1 < k) {
			for (auto e : g[1][uu]) {
				if (dis[e.fi][uk + 1] > dis[uu][uk] + e.se) {
					dis[e.fi][uk + 1] = dis[uu][uk] + e.se;
					if (!in[e.fi][uk + 1]) {
						in[e.fi][uk + 1] = true;
						que.push({e.fi, uk + 1});
					}
				}
			}
		}
		in[uu][uk] = false;
	}
}
void solve() {
	cin >> n >> m >> k; k++;
	rep(_, 0, 2) rep(i, 0, n) g[_][i].clear();
	rep(i, 0, m) {
		int a, b, w; cin >> a >> b >> w; a--, b--;
		g[0][a].pb({b, w});
		g[0][b].pb({a, w});
		vi v; gao(w, v);
		int nw = INT_MAX;
		for (auto e : v) {
			int tmp = w / e + 2 * e;
			nw = min(nw, tmp);
		}
		if (nw < w) {
			g[1][a].pb({b, nw});
			g[1][b].pb({a, nw});
		}
	}
	int S, T; cin >> S >> T; S--, T--;
	spfa(S);
	ll ans = LLONG_MAX;
	rep(i, 0, k) ans = min(ans, dis[T][i]);
	if (ans == LLONG_MAX) cout << -1 << endl;
	else cout << ans << endl;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
  int tcas; cin >> tcas;
  rep(cas, 0, tcas) solve();
	return 0;
}
