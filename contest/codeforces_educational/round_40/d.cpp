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
const int N = 1e3 + 7;
int n, m, s, t, diss[N], dist[N];
bool rod[N][N];
vi g[N];
void dij(int s, int dis[]) {
	fill_n(dis, n, INT_MAX); dis[s] = 0;
	priority_queue<pii> stk; stk.push({-dis[s], s});
	while (!stk.empty()) {
		int _d, u;
		tie(_d, u) = stk.top(); stk.pop();
		if (_d != -dis[u]) continue;
		for (auto v : g[u]) {
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				stk.push({-dis[v], v});
			}
		}
	}
}
int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t), s--, t--;
    rep(i, 0, m) {
    	int a, b; scanf("%d%d", &a, &b), a--, b--;
    	rod[a][b] = rod[b][a] = true;
    	g[a].pb(b);
    	g[b].pb(a);
	}
    dij(s, diss);
    dij(t, dist);
    int ans = 0;
    rep(i, 0, n) rep(j, i + 1, n) if (!rod[i][j]) {
		int new_path = min(diss[i] + dist[j] + 1, diss[j] + dist[i] + 1);
		if (new_path >= diss[t]) ans++;
	}
	cout << ans;
	return 0;
}
