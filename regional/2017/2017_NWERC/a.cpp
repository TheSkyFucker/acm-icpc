#include <bits/stdc++.h>
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
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,l,r) for(int i=(r)-1;i>=(l);i--)
#define dd(x) cout << #x << " = " << (x) << ", "
#define de(x) cout << #x << " = " << (x) << "\n"
#define endl "\n"
#define in(x) ((x) << 2)
#define ot(x) ((x) << 2 | 1)
#define dn(x) ((x) << 2 | 2)
#define up(x) ((x) << 2 | 3)
//-----
const int N = 1e6 + 7, INF = 1e9 + 7;
int n, a[N], m, cnt[N];
vi tab[N];
vector<pii> g[N << 2];
int deg[N << 2], dis[N << 2];
void gao(int n, int S) {
	fill_n(dis, n, INF); dis[S] = 1;
	rep(u, 0, n) for (auto e : g[u]) deg[e.fi]++;
	queue<int> que;
	rep(u, 0, n) if (!deg[u]) que.push(u);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (auto e : g[u]) {
			if (dis[e.fi] > dis[u] + e.se) {
				dis[e.fi] = dis[u] + e.se;
			}
			if (!--deg[e.fi]) que.push(e.fi);
		}
	}
}	
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	rep(i, 0, n) cin >> a[i]; a[n++] = 0;
	n = unique(a, a + n) - a;

	vi v(a, a + n);
	sort(all(v)); v.erase(unique(all(v)), v.end());
	rep(i, 0, n) a[i] = lower_bound(all(v), a[i]) - v.begin();
	a[n++] = sz(v);
	v.pb(INT_MAX);
	rep(i, 0, n) cnt[a[i]]++;

	rep(i, 0, n - 1) if (a[i] + 1 == a[i + 1])
		g[ot(i)].pb({in(i + 1), cnt[a[i]] - 1});

	rep(i, 0, n) tab[a[i]].pb(i);
	rep(i, 0, sz(v)) {
		if (sz(tab[i]) == 1) {
			int a = tab[i][0];	
			g[in(a)].pb({dn(a), 0});
			g[in(a)].pb({up(a), 0});
		}

		rep(j, 1, sz(tab[i])) {
			int b = tab[i][j], a = tab[i][j - 1];
			g[dn(b)].pb({dn(a), 0});
			g[in(b)].pb({dn(a), 0});
			g[up(a)].pb({up(b), 0});
			g[in(a)].pb({up(b), 0});
		}

		rep(j, 0, sz(tab[i])) {
			int a = tab[i][j];
			g[dn(a)].pb({ot(a), 0});
			g[up(a)].pb({ot(a), 0});
			if (i + 1 < sz(v)) {
				g[ot(a)].pb({up(tab[i + 1][0]), cnt[::a[a]]});
			}
		}
	}
	gao(n * 4, in(n - 2));
	cout << dis[ot(n - 1)] - 3;
	return 0;
}
