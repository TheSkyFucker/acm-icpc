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
const int N = 1e5 + 7;
int n;
vector<pii> g[N];

int dp[N];
void dfs(int u, int fa) {
	dp[u] = 0;
	for (auto v : g[u]) {
		if (v.fi == fa) continue;
		dfs(v.fi, u);
		dp[u] = max(dp[u], dp[v.fi] + v.se); 
	}
}

void solve() {
	rep(i, 1, n + 1) g[i].clear();
	ll ans = 0;
	rep(i, 1, n) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c); ans += c * 2;
		g[a].pb({b, c});
		g[b].pb({a, c});
	}
	dfs(1, 0);
	printf("%lld\n", ans - dp[1]);
}

int main() {
	while (~scanf("%d", &n)) solve();
	return 0;
}
