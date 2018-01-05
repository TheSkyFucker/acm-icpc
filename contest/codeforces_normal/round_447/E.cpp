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
const int N = 1e6 + 7;

int bel[N];
struct Tarjan {
    static const int N = ::N;
    int dfn[N], low[N], tim;
    int stk[N], top;
    vector<vi> scc;
    vector<vector<pii> > ng;
    void dfs(int u, vi g[]) {
        low[stk[top++] = u] = dfn[u] = tim++;
        for (auto v : g[u])
            if (!~dfn[v])
                dfs(v, g), low[u] = min(low[u], low[v]);
            else if (!~bel[v])
                low[u] = min(low[u], dfn[v]);
        if (low[u] == dfn[u]) {
            scc.pb(vi());
            do {
                scc.back().pb(stk[--top]);
                bel[stk[top]] = sz(scc);
            }   while (stk[top] != u);
        }
    }
    void solve(int n, vi g[], vi gw[]) {
        scc.clear(); ng.clear();
        fill_n(dfn, n, -1); tim = 0;
        fill_n(bel, n, -1); top = 0;
        rep(i, 0, n) if (!~dfn[i]) dfs(i, g);
        rep(i, 0, n) bel[i]--;
        ng.resize(sz(scc));
        rep(i, 0, n) {
        	rep(j, 0, sz(g[i])) {
        		int v = g[i][j]; if (bel[i] == bel[v]) continue;
        		ng[bel[i]].pb({bel[v], gw[i][j]});
			}
		}
        		
    }
}   tar;

int n, m, nn, S, deg[N];
ll val[N], dis[N];
vi g[N], gw[N];
ll sum1(ll n) { return (1 + n) * n / 2; }
ll sum2(ll n) { return n * (n + 1) * (2 * n + 1) / 6; }
void solve() {
	rep(i, 0, n) g[i].clear(), gw[i].clear();
	rep(i, 0, m) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c); a--; b--;
		g[a].pb(b); gw[a].pb(c);
	}
	tar.solve(n, g, gw); nn = sz(tar.scc);
	fill_n(val, n, 0);
	rep(i, 0, n) {
		rep(j, 0, sz(g[i])) {
			int v = g[i][j]; if (bel[i] != bel[v]) continue;
			int l = gw[i][j];
			int mxi = sqrt(l * 2); while (mxi * (mxi + 1) > l * 2) mxi--;
			val[bel[i]] += (1ll * (mxi + 1) * l - (sum2(mxi) + sum1(mxi)) / 2);
		}
	}
	scanf("%d", &S);S--;
	fill_n(deg, nn, 0);
	rep(i, 0, nn) for (auto v : tar.ng[i]) deg[v.fi]++;
	rep(i, 0, nn) dis[i] = -1; dis[bel[S]] = val[bel[S]];
	queue<int> que; rep(i, 0, nn) if (!deg[i]) que.push(i);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (auto v : tar.ng[u]) {
			if (~dis[u] && 
				dis[v.fi] < dis[u] + v.se + val[v.fi])
				dis[v.fi] = dis[u] + v.se + val[v.fi];
			if (!--deg[v.fi]) {
				que.push(v.fi);
			}
		}
	}
	ll ans = 0;
	rep(i, 0, nn) ans = max(ans, dis[i]);
	printf("%lld\n", ans);
}

int main() {
	while (~scanf("%d%d", &n, &m))solve();	

	return 0;
}
