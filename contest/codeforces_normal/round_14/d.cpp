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
const int N = 2e2 + 7;
int n, deg[N];
vi g[N];

int far[N];
void bud(int u, int fa = -1) {
	far[u] = fa;
	for (auto v : g[u]) {
		if (v == fa) continue;
		bud(v, u);
	}
}

int mx[N], dp[N], use[N];
void dfs(int u, int fa = -1) {
	mx[u] = 0;
	dp[u] = 0;
	int mx1 = 0, mx2 = 0;
	for (auto v : g[u]) {
		if (use[v]) continue;
		if (v == fa) continue;
		dfs(v, u);
		mx[u] = max(mx[u], mx[v]);
		if (dp[v] + 1 > mx1) {
			mx2 = mx1;
			mx1 = dp[v] + 1;
		} else if (dp[v] + 1 > mx2) {
			mx2 = dp[v] + 1;
		}
	}
	dp[u] = mx1;
	mx[u] = max(mx[u], mx1 + mx2);
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		g[a].pb(b); deg[b]++;
		g[b].pb(a); deg[a]++;
	}
	int ans = 0;
	rep(i, 0, n) {
		bud(i);
		rep(j, 0, n) {
			vi v; for (int k = j; ~k; k = far[k]) v.pb(k);
			for (auto k : v) use[k] = true;
			for (auto k : v) {
				for (auto s : g[k]) if (!use[s]) {
					dfs(s, k);
					ans = max(ans, mx[s] * (sz(v) - 1));
				}
			}
			for (auto k : v) use[k] = false;
		}
	}
	printf("%d\n", ans);
	return 0;
}
