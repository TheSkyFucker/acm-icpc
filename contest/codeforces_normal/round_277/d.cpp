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
const int N = 2e3 + 7, MOD = 1e9 + 7;
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return 1ll * a * b % MOD; }
int n, d, a[N], dp[N], rnk[N];
vi g[N];
void dfs(int mi, int mx_r, int u, int fa) {
	dp[u] = 1;
	for (auto v : g[u]) {
		if (v == fa || a[v] < mi || rnk[v] > mx_r) continue;
		dfs(mi, mx_r, v, u);
		dp[u] = mul(dp[u], dp[v] + 1);
	}
}
int main() {
	scanf("%d%d", &d, &n);
	rep(i, 0, n) scanf("%d", a + i);
	rep(i, 1, n) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	vector<pii> v; v.resize(n);
	rep(i, 0, n) v[i] = {a[i], i};
	sort(all(v));
	rep(i, 0, n) rnk[v[i].se] = i;
	int ans = 0;
	rep(i, 0, n) {
		dfs(v[i].fi - d, i, v[i].se, -1);
		ans = add(ans, dp[v[i].se]);
	}
	printf("%d", ans);
	return 0;
}
